#include <i18n.hpp>

#include <fstream>
#include "thirdparty/nlohmann/json.hpp"

std::unordered_map<std::string, std::unordered_map<std::string, std::string>> i18n::_translations;
std::string i18n::_language = "en_us";

void i18n::load(const std::filesystem::path &path) {
	_translations.clear();
	for (const std::filesystem::directory_entry &entry : std::filesystem::directory_iterator{path}) {
		std::string language = entry.path().stem().string();
		_translations[language] = std::unordered_map<std::string, std::string>{};
		if (!entry.is_regular_file() || entry.path().extension() != ".json") {
			continue;
		}

		std::ifstream file{entry.path()};
		if (!file) {
			continue;
		}

		std::string content;
		content.assign(std::istreambuf_iterator(file), std::istreambuf_iterator<char>());

		nlohmann::json json = nlohmann::json::parse(content);
		for (auto &[key, value] : json.items()) {
			_translations[language][key] = value.get<std::string>();
		}
	}
}

bool i18n::has_lang(const std::string &locale) {
	return _translations.contains(locale);
}

void i18n::set_lang(const std::string &locale) {
	_language = locale;
}

std::string i18n::get(const std::string &key) {
	const std::string language = _translations.contains(_language) ? _language : "en_us";
	return _translations[language].contains(key) ? _translations[language][key] : "i18n{" + key + " is undefined}";
}
