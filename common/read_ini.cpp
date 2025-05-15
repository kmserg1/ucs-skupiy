#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

int main() {
    std::ifstream file("config.ini");
    std::map<std::string, std::string> ucsParameters;
    std::string line;

    while (std::getline(file, line)) {
        // Пропускаємо порожні рядки та коментарі
        if (line.empty() || line[0] == ';' || line[0] == '#')
            continue;

        size_t pos = line.find(':');
        if (pos == std::string::npos)
            continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        // Обрізаємо пробіли
        key.erase(0, key.find_first_not_of(" \t"));
        key.erase(key.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);

        ucsParameters[key] = value;
    }

    // Вивід зчитаних змінних
    for (const auto& [key, value] : ucsParameters) {
        std::cout << key << " = " << value << std::endl;
    }

    // Доступ до значення за ключем:
    // std::string myValue = variables["myKey"];

   std::cout << ucsParameters["start_week"] << '\n';

    return 0;
}
