# i18n - Простая C++ библиотека для интернационализации

> Создана *исключительно* в целях изучения C++.

Легковесная библиотека, позволяющая хранить файлы переводов в формате
JSON и получать локализованные строки во время выполнения.

---

## Пример использования

```cpp
#include <i18n.hpp>
#include <nlohmann/json.hpp> // <- опционально
#include <iostream>
#include <filesystem>

int main() {
    // Загрузка всех файлов перевода
    i18n::load(std::filesystem::current_path() / "resources/lang", ".json", [] (const std::string &content) -> std::unordered_map<std::string, std::string> {
        // Логика парсера
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

## Сборка

Для того чтобы собрать эту библиотеку Вам всего лишь нужно написать эти команды в терминале:

```shell
mkdir build && cd build

cmake -G Ninja ..
ninja
```
