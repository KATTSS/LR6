#include <cwctype> 
#include <iostream>
#include "headerLr6.h"
void inputArr(wchar_t *&arr, int &size, int &capacity)
{
    // size = 0;
    // capacity = 10;
    // arr = new wchar_t[capacity];
    wchar_t el;

    std::wcout << L"Введите строку: \n";
    while ((el = std::getwchar()) != L'\n')
    {
        if (size == capacity - 1)
        {
            capacity *= 2;
            wchar_t *newArr = new wchar_t[capacity];
            std::wmemcpy(newArr, arr, size);
            delete[] arr;
            arr = newArr;
            delete [] newArr;
        }
        arr[size++] = el;
    }
    arr[size] = L'\0';
}

void input_c_string(wchar_t *arr, int size)
{
    wchar_t el;
    int i = 0;
    while ((el = std::getwchar()) != L'\n' && i < size - 1)
    {
        arr[i] = el;
        ++i;
    }
    arr[i] = L'\0';
}