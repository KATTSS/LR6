#include <iostream>
#include <cwctype>
#include "headerLr6.h"
void MYstrcat(wchar_t *&one, int size1, wchar_t *&two, int size2);
// void MYstrcpy(wchar_t *&one, int size1, wchar_t *&two, int size2, int n);
void inputArr(wchar_t *&arr, int &size, int &capacity);
int MYstrcmp(wchar_t *one, int size1, wchar_t *two, int size2);

int main()
{
    int cap1 = 10, cap2 = 10;
    int size1 = 0, size2 = 0;

    wchar_t *one = new wchar_t[cap1];
    wchar_t *two = new wchar_t[cap2];

    inputArr(one, size1, cap1);
    inputArr(two, size2, cap2);

    int res = MYstrcmp(one, size1, two, size2);
    std::wcout << res << '\n';
    MYstrcat(one, size1, two, size2);
    // MYstrcpy(one, size1, two, size2, 100);

    delete[] one;
    delete[] two;
    return 0;
}
int MYstrcmp(wchar_t *one, int size1, wchar_t *two, int size2)
{
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

void MYstrcat(wchar_t *&one, int size1, wchar_t *&two, int size2)
{
    wchar_t *added = new wchar_t[size1 + size2];
    std::wmemcpy(added, one, size1);
    //delete[] one;

    for (int i = 0; i < size2; i++)
    {
        added[size1+i] = two[i];
    }
    added[size1]='\0';
    one[0]='\0';
    one = added;
    std::wcout << one << '\n';
    delete [] added;
}

// void MYstrcpy(wchar_t *&one, int size1, wchar_t *&two, int size2, int n)
// {
//     if (size1 < size2)
//     {
//         std::cout << "full copying is impossible" << '\n';
//         size2 = size1;
//     }
//     if (n >= size2)
//         n = size2;
//     for (int i = 0; i < n; ++i)
//     {
//         one[i] = two[i];
//     }
//     std::wcout << one << '\n';
// }