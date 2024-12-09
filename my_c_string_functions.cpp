#include <iostream>
#include <cwctype>
#include <wchar.h>
#include "headerLr6.h"

int meinstrcmp(wchar_t *one, wchar_t *two)
{
    int size1 = wcslen(one);
    int size2 = wcslen(two);
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (one[i] > two[j])
            return 1;
        else if (one[i] < two[j])
            return -1;
        else
        {
            ++i;
            ++j;
        }
    }
    if (size1 > size2)
        return 1;
    else if (size1 < size2)

        return -1;
    else
        return 0;
}

void meinstrcat(wchar_t *&one, wchar_t *two)
{
    int size1 = wcslen(one);
    int size2 = wcslen(two);
    wchar_t *both_in_one = new wchar_t[size1 + size2 + 1];
    for (int i = 0; i <= size1; ++i)
    {
        both_in_one[i] = one[i];
    }
    for (int i = 0; i < size2; ++i)
    {
        both_in_one[size1 + i] = two[i];
    }
    both_in_one[size1 + size2] = '\0';
    delete[] one;
    one = both_in_one;
}

void meinstrcpy(wchar_t *&one, wchar_t *two, int n)
{
    int size1 = wcslen(one);
    int size2 = wcslen(two);
    if (size1 < size2)
    {
        std::wcout << "full copying is impossible" << '\n';
        size2 = size1;
    }
    else if (n >= size2)
        std::wcout << "full copying is impossible" << '\n';
    n = size2;
    for (int i = 0; i < n; ++i)
    {
        one[i] = two[i];
    }
    // std::wcout << one << '\n';
}

void cleaner(wchar_t *&arr, int &size, int &capacity)
{
    int new_capacity = 10;
    int new_size = 0;
    wchar_t *newarr = new wchar_t[new_capacity];

    for (int i = 0; arr[i] != L'\0'; ++i)
    {
        if (new_size == new_capacity - 1)
        {
            new_capacity *= 2;
            wchar_t *newArr = new wchar_t[new_capacity];
            std::wmemcpy(newArr, newarr, new_size);
            delete[] newarr;
            newarr = newArr;
        }
        if (arr[i] == L' ' || iswalpha(arr[i]))
        {
            newarr[new_size++] = arr[i];
        }
    }
    newarr[new_size] = L'\0';

    delete[] arr;
    arr = newarr;
    size = new_size;
    capacity = new_capacity;

    // std::wcout << arr;
}

void chech(wchar_t *buf, int bufsize, wchar_t *&ps, int &pssize)
{
    int countminus = 0;
    int countpoint = 0;
    if (buf[0] == L'.')
        return;
    for (int i = 0; i < bufsize; ++i)
    {
        if (buf[i] == L'-' && isdigit(buf[i + 1]) == true)
            ++countminus;
        if (buf[i] == L'.')
        {
            ++countpoint;
            if (isdigit(buf[i + 1]) != true || isdigit(buf[i - 1]) != true)
            {
                return;
            }
        }
        if (buf[i] == L'-' && (isdigit(buf[i + 1]) == false || isdigit(buf[i - 1]) == true))
            return;
        if (countminus > 1 || (buf[i] == L'-' && !isdigit(buf[i + 1]) && isdigit(buf[i - 1] == true)) || countpoint > 1)
        {
            return;
        }
    }
    for (int k = 0; k < bufsize; ++k)
    {
        ps[pssize] = buf[k];
        ++pssize;
    }

    if (buf[0] != L'\0')
    {
        ps[pssize] = ' ';
        ++pssize;
    }
    ps[pssize] = L'\0';
    // std::wcout << ps;
}