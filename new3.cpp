#include <iostream>
#include <cwctype>
#include <wchar.h>
#include "headerLr6.h"
#include <string>

int main() {
    int size = 201;
    wchar_t *one = new wchar_t[size];
    wchar_t *two = new wchar_t[size];

    input_c_string(one, size);
    input_c_string(two, size);

    int taskexit = 0;
    while (taskexit == 0) {
        menutask3();
        
        std::string s;
        int y = 0;  // Инициализируем переменную y

        do {
            std::wcout << "Введите номер выбранной функции: ";
            std::getline(std::cin, s);
            y = std::atoi(s.c_str());
            std::wcout << "Полученное значение: " << y << std::endl;
            if (s.find_first_not_of("1234") != std::string::npos) {
                std::wcout << "Неправильный ввод, попробуйте снова.\n";
            }
            if (y < 1 || y > 4) {
                std::wcout << "Введите число от 1 до 4.\n";
            }
        } while (s.find_first_not_of("1234") != std::string::npos || y < 1 || y > 4);

        switch (y) {
            case 1: {
                int res = meinstrcmp(one, two);
                std::wcout << res << '\n'
                           << "one: " << one << '\n'
                           << "two: " << two << '\n';
                break;
            }
            case 2: {
                meinstrcat(one, two);
                std::wcout << "one: " << one << '\n'
                           << "two: " << two << '\n';
                break;
            }
            case 3: {
                meinstrcpy(two, one, 100);
                std::wcout << "one: " << one << '\n'
                           << "two: " << two << '\n';
                break;
            }
            case 4: {
                taskexit = 1;
                break;
            }
        }
    }

    delete[] one;
    delete[] two;
    return 0;
}
