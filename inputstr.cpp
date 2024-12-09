#include <cwctype> 
#include <iostream>
#include <limits>
#include "headerLr6.h"
#include <locale>


void input_c_string(wchar_t *arr, int size)
{   std::wcout << L"Введите строку: " << '\n';
    wchar_t el;
    int i = 0;
    while ((el = std::getwchar()) != L'\n' && i < size - 1)
    {
        arr[i] = el;
        ++i;
    }
    arr[i] = L'\0';
}

void menu() 
{

    std::wcout << L"\nAuthor- 1" << std::endl;
    std::wcout << L"Task 1 - 2" << std::endl;
    std::wcout << L"Task 2 - 3" << std::endl;
    std::wcout << L"Task 3 - 4" << std::endl;
    std::wcout << L"Меню - 5" << std::endl;
    std::wcout << L"Выход - 6" << std::endl;
}

void menutask3()
{

    std::wcout << L"\nМой аналог strcmp(s1,s2)(сравнение строк)- 1" << std::endl;
    std::wcout << L"Мой аналог strcat(s1,s2)(объединение строк) - 2" << std::endl;
    std::wcout << L"Мой аналог strcpy(s1,s2)(копирование строк) - 3" << std::endl;
    std::wcout << L"Выход из задания - 4" << std::endl;   
}


void meininputarray(wchar_t *&array, int &size) {
    //std::locale::global(std::locale(""));
    std::setlocale(LC_ALL, "en_US.UTF-8");
    std::wcout << "Vvedite stroky: " << '\n';
    wchar_t el;
    int i=0;
   
    while ((el = std::getwchar()) != L'\n') {
        if (i>=size-1) {
            size*=2;
            wchar_t *biggerarray=new wchar_t[size];
            std::wmemcpy(biggerarray, array, i);
            delete [] array;
            array = biggerarray;
        }
        array[i]=el;
        ++i;
    }
    array[i]=L'\0';
}