#include <iostream>
#include <cwctype>
#include <wchar.h>
#include "headerLr6.h"
#include <string>

int task3()
{
    int size = 201;
    wchar_t *one = new wchar_t[size];
    wchar_t *two = new wchar_t[size];

    input_c_string(one, size);
    // std::wcout << one << '\n';
    input_c_string(two, size);
    // std::wcout << two << '\n';
    int taskexit = 0;
    menutask3();
    while (taskexit==0)
    {
        //int y=vvod();
        std::wstring s;
        int y=0;

        do
        {   std::wcout << "\nВведите номер выбранной функции: ";
            std::getline(std::wcin, s);
            y = std::wcstol(s.c_str(), nullptr, 10);
        } while (s.find_first_not_of(L"1234") != std::wstring::npos || y < 1 || y > 4);

        if (y==1)
        {
            int res = meinstrcmp(one, two);
            std::wcout << res << '\n'
                       << "one: " << one << '\n'
                       << "two: " << two << '\n';
            
        }
        else if (y==2)
        {
            meinstrcat(one, two);
            std::wcout << "one: " << one << '\n'
                       << "two: " << two << '\n';
           
        }
        else if (y==3)
        {
            meinstrcpy(two, one, 100);
            std::wcout << "one: " << one << '\n'
                       << "two: " << two << '\n';
           
        }
        else
        {
            taskexit = 1;
        }
        }
    

    delete[] one;
    delete[] two;
    return 0;
}
