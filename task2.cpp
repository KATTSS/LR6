// actually task2
#include <iostream>
#include <cwctype>
#include <locale>
#include "headerLr6.h"

//void cleaner(wchar_t *&arr, int &size, int &capacity);

int task2()
{   
    //std::locale::global(std::locale(""));
    std::setlocale(LC_ALL, "en_US.UTF-8");
    int capacity = 10, size = 0;
    wchar_t *arr = new wchar_t[capacity];
   
    meininputarray(arr, capacity);

    cleaner(arr, size, capacity);
    std::wcout << "Очищенная строка: " << arr << '\n';

    delete[] arr;
    return 0;
}

