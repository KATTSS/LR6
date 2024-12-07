#include <cwctype> 
#include <iostream>
#include "headerLr6.h"

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

void menu() //needs redaction
{

    std::cout << "\nСуть программы - 1" << std::endl;
    std::cout << "Кто выполнил задание? - 2" << std::endl;
    std::cout << "Запуск программы - 3" << std::endl;
    std::cout << "Завершить программу - 4" << std::endl;
    std::cout << "Меню - 5\n"
              << std::endl;
}

void menutask3()
{

    std::cout << "\nMy analog strcmp(s1,s2)(sravnenie strok)- 1" << std::endl;
    std::cout << "My analog strcat(s1,s2)(ob'edinenie strok) - 2" << std::endl;
    std::cout << "My analog strcpy(s1,s2)(kopirovanie strok) - 3" << std::endl;
    std::cout << "Vyhod iz zadaniya - 4" << std::endl;   
}

int vvod()
{
    std::string s;
    int x;
    do
    {
        std::getline(std::cin, s);
        x = std::atoi(s.c_str());
    } while (s.find_first_not_of("1234567890") != std::string::npos);
    return x;
}

void meininputarray(wchar_t *&array, int &size) {
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