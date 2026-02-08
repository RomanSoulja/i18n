#ifndef I18N
#define I18N

#include <filesystem>
#include <string>
#include <unordered_map>

class i18n {
	static std::unordered_map<std::string, std::unordered_map<std::string, std::string>> _translations;
	static std::string _language;
	public:
		static void load(const std::filesystem::path &path);

		static bool has_lang(const std::string &locale);

		static void set_lang(const std::string &locale);

		static std::string get(const std::string &key);
};

#endif
