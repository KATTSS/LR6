#include <cwctype>
#include <wchar.h>
#include <iostream>
#include <string>
#include <limits> 
#include <locale>
#include "headerLr6.h"
int main()
{    std::setlocale(LC_ALL, "en_US.UTF-8");
    bool exit = false;

    menu();

    while (!exit)
    {
        int x;
        std::wstring s;

        do
        {
            std::wcout << L"Введите номер желаемой операции: ";
            std::getline(std::wcin, s);
            x = std::wcstol(s.c_str(), nullptr, 10);
        } while (s.find_first_not_of(L"123456") != std::wstring::npos || x < 1 || x > 6);
       
        switch (x)
        {
        case 1:
            std::wcout << L"Буткевич Екатерина, группа 453501, вариант  7" << std::endl;
            break;

        case 2:
            
            task1();
            //std::getline(std::cin, s);
            break;

        case 3:
            //std::wcin.ignore();
            task2();
            //std::getline(std::cin, s);
            break;

        case 4:
            task3();
            //std::getline(std::cin, s);
            break;
        case 5:
            menu();
            break;

        case 6:
            exit = true;
            break;
        }
    }
    return 0;
}