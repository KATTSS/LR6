//actually task2
#include <iostream>
#include <cwctype> 
#include "headerLr6.h"


void cleaner(wchar_t *&arr, int &size, int &capacity);

int main()
{
    int capacity = 10, size = 0;
    wchar_t *arr = new wchar_t[capacity];
    //inputArr(arr, size, capacity);
    meininputarray(arr, capacity); 
    cleaner(arr, size, capacity);
    std::wcout << "Clean string: " << arr << '\n';
    delete [] arr;
    return 0;
}


void cleaner(wchar_t *&arr, int &size, int &capacity)
{
    int new_capacity = 10;
    int new_size = 0;
    wchar_t *newarr = new wchar_t[new_capacity];
    
    for (int i = 0; arr[i]!=L'\0'; ++i) 
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

    //std::wcout << arr;
}
