#pragma once

#include <filesystem>
#include <functional>
#include <string>

namespace i18n {
	void set_language(const std::string &code);

	std::string current_language();

	std::string get(const std::string &key);

	void load(const std::filesystem::path &path, const std::string &extension, const std::function<std::unordered_map<std::string, std::string>(const std::string &content)> &parser);
}
