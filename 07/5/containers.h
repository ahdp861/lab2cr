#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <iostream>
#include <deque>
#include <list>
#include <fstream>
#include <ctime>
using namespace std;

template <typename container>
//void Input(container& N, int n)//Заполнение контейнеров FIX ME некорректное название
void input(container& container, int container_size);

template <typename container>
//void Print(const container& container)//Вывод содержимого контейнеров FIX ME некорректное название
void print_elements(const container& container);

//void Insert(deque<int>& D, list<int>& L)//Вставка перед 5 с конца элемента списка последних 5 элементов дека в обратном порядке FIX ME некоректное название
void insert(deque<int>& my_deque, list<int>& my_list);

#endif
