#include "i18n.hpp"

#include <fstream>

static std::unordered_map<std::string, std::unordered_map<std::string, std::string>> translations;
static std::string default_language = "en_us";
static std::string language = default_language;

void i18n::set_language(const std::string &code) {
	language = code;
}

std::string i18n::current_language() {
	return language;
}

std::string i18n::get(const std::string &key) {
	const std::string lang = translations.contains(language) ? language : default_language;
	return translations[lang].contains(key) ? translations[lang][key] : "i18n{lang=" + lang + ", key=" + key + "}";
}

std::string read(const std::ifstream& file) {
	std::ostringstream stream;
	stream << file.rdbuf();
	return stream.str();
}

void i18n::load(const std::filesystem::path &path, const std::string &extension, const std::function<std::unordered_map<std::string, std::string>(const std::string &content)> &parser) {
	translations.clear();
	for (const std::filesystem::directory_entry &entry: std::filesystem::directory_iterator{path}) {
		if (!entry.is_regular_file() || entry.path().extension() != extension) {
			continue;
		}

		std::ifstream file{entry.path()};
		if (!file) {
			continue;
		}

		translations[entry.path().stem().string()] = parser(read(file));
		file.close();
	}
}
