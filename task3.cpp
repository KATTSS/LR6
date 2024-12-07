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
    int taskexit = 0;
    menutask3();
    while (taskexit==0)
    {
        //int y=vvod();
        std::string s;
        int y=0;

        do
        {   std::wcout << "vvedite nomer bybrannoj functsyy: ";
            std::getline(std::cin, s);
            y = std::atoi(s.c_str());
        } while (s.find_first_not_of("1234") != std::string::npos || y < 1 || y > 4);

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
