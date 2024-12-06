#include <iostream>
#include <cwctype>
#include <wchar.h>
#include "headerLr6.h"
void input_c_string(wchar_t *arr, int size);
int meinstrcmp(wchar_t *one, wchar_t *two);
void meinstrcat(wchar_t *&one, wchar_t *two);
void meinstrcpy(wchar_t *&one, wchar_t *two, int n);
int main()
{
    int size = 201;
    wchar_t *one = new wchar_t[size];
    wchar_t *two = new wchar_t[size];

    input_c_string(one, size);
    // std::wcout << one << '\n';
    input_c_string(two, size);
    // std::wcout << two << '\n';

    int res = meinstrcmp(one, two);
    std::wcout << res << '\n';

    meinstrcat(one, two);
    std::wcout << one << '\n';

    meinstrcpy(two, one, 100);
    std::wcout << "one: " << one << '\n'
               << "two: " << two << '\n';

    delete[] one;
    delete[] two;
    return 0;
}


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
    } else if (n >= size2)
        std::wcout << "full copying is impossible" << '\n';
        n = size2;
    for (int i = 0; i < n; ++i)
    {
        one[i] = two[i];
    }
    // std::wcout << one << '\n';
}