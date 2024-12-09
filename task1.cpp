#include <iostream>
#include <cstdio>
#include <limits> 
#include "headerLr6.h"

//void chech(char *buf, int bufsize, char *ps, int &pssize);

int task1()
{
    wchar_t *s = new wchar_t[81];
    wchar_t c;
    int i = 0;
    std::wcout << L"Введите строку: ";
    
    while ((c = getwchar()) != '\n' && i<80)
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    // Катя лапочка <3
    //std::wcout << L"Vvedennaya stroka: " << s << '\n';
    i = 0;
    wchar_t *ps = new wchar_t[81];
    wchar_t *buf = new wchar_t[81];

    int pssize = 0;
    for (int j = 0; j < 81; j++)
    {

        if (s[j] == '-' || isdigit(s[j]) == true || s[j] == '.')
        {
            buf[i++] = s[j];
        }
        else
        {
            chech(buf, i, ps, pssize);
            buf[0] = '\0';
            i = 0;
        }
    }
    std::wcout << L"Очищенная строка: " << ps << '\n';
    delete[] s;
    delete[] ps;
    delete[] buf;
    return 0;
}
