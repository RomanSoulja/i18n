## i18n – Simple C++ Internationalization Library

> Created *exclusively* for learning C++.

A lightweight library that lets you store translation files
and retrieve localized strings at runtime.

---  

### Usage Example

```cpp
#include <i18n.hpp>
#include <nlohmann/json.hpp> // <- optional
#include <iostream>
#include <filesystem>

int main() {
    // Load all translation files
    i18n::load(std::filesystem::current_path() / "resources/lang", ".json", [] (const std::string &content) -> std::unordered_map<std::string, std::string> {
        // Parser's logic
        const nlohmann::json json = nlohmann::json::parse(content);
        return json.get<std::unordered_map<std::string, std::string>>();
    });
    
    std::cout << i18n::get("greeting") << std::endl; // -> Hello!
    i18n::set_language("ru_ru");
    std::cout << i18n::get("greeting") << std::endl; // -> Привет!
    return 0;
}
```

---  

### Build

To build the library, just run the following commands in a terminal:

```shell
mkdir build && cd build

cmake -G Ninja ..
ninja
```
