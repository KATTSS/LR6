#pragma once
#include <cwctype> 
#include <wchar.h>
#include <iostream>
#include <locale>

void input_c_string(wchar_t *arr, int size);
void meininputarray(wchar_t *&array, int &size);

int meinstrcmp(wchar_t *one, wchar_t *two);
void meinstrcat(wchar_t *&one, wchar_t *two);
void meinstrcpy(wchar_t *&one, wchar_t *two, int n);

void cleaner(wchar_t *&arr, int &size, int &capacity);
void chech(wchar_t *buf, int bufsize, wchar_t *&ps, int &pssize);

void menutask3();
void menu();

//int vvod();

int task1();
int task2();
int task3();
