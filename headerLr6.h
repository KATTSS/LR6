#pragma once
#include <cwctype> 
#include <wchar.h>
#include <iostream>
void inputArr(wchar_t *&arr, int &size, int &capacity);
void input_c_string(wchar_t *arr, int size);

int meinstrcmp(wchar_t *one, wchar_t *two);
void meinstrcat(wchar_t *&one, wchar_t *two);
void meinstrcpy(wchar_t *&one, wchar_t *two, int n);

void menutask3();
void menu();