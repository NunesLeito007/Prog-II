#include <iostream>
#include <string>

std::pair<bool, int> encontrarSubstring(const std::string& str, const std::string& substr) {
    size_t pos = str.find(substr);
    if (pos != std::string::npos) {
        return {true, static_cast<int>(pos)};
    } else {
        return {false, -1};
    }
}

int main() {
    std::string str;
    std::string substr;

    // Solicita ao usuário que insira a string principal
    std::cout << "Digite a string: ";
    std::cin >> str;

    // Solicita ao usuário que insira a substring a ser procurada
    std::cout << "Digite a substring: ";
    std::cin >> substr;

    auto resultado = encontrarSubstring(str, substr);

    if (resultado.first) {
        std::cout << "Substring encontrada na posição: " << resultado.second << std::endl;
    } else {
        std::cout << "Substring não encontrada." << std::endl;
    }

    return 0;
}
