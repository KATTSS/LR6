#include <iostream>
#include <cwctype>
#include <wchar.h>
#include "headerLr6.h"
#include <string>
// void input_c_string(wchar_t *arr, int size);
// int meinstrcmp(wchar_t *one, wchar_t *two);
// void meinstrcat(wchar_t *&one, wchar_t *two);
// void meinstrcpy(wchar_t *&one, wchar_t *two, int n);
int main()
{
    int size = 201;
    wchar_t *one = new wchar_t[size];
    wchar_t *two = new wchar_t[size];

    input_c_string(one, size);
    // std::wcout << one << '\n';
    input_c_string(two, size);
    // std::wcout << two << '\n';
    bool taskexit = false;
    menutask3();
    while (!taskexit)
    {

        std::string s;
        int x;

        do
        {
            std::getline(std::cin, s);
            x = std::atoi(s.c_str());
        } while (s.find_first_not_of("1234") != std::string::npos || x < 1 || x > 4);

        switch (x)
        {
        case 1:
        {
            int res = meinstrcmp(one, two);
            std::wcout << res << '\n'
                       << "one: " << one << '\n'
                       << "two: " << two << '\n';
            break;
        }
        case 2:
        {
            meinstrcat(one, two);
            std::wcout << "one: " << one << '\n'
                       << "two: " << two << '\n';
            break;
        }
        case 3:
        {
            meinstrcpy(two, one, 100);
            std::wcout << "one: " << one << '\n'
                       << "two: " << two << '\n';
            break;
        }
        case 4:
        {
            taskexit = true;
            break;
        }
        }
    }

    delete[] one;
    delete[] two;
    return 0;
}
