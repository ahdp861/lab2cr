#ifndef QUEUE_H
#define QUEUE_H

//#include <windows.h> FIX ME ненужный include
#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node* next;
};
typedef Node* PNode;

//void add(int data, PNode& Head, PNode& tail) FIX ME некорректное название
void add(int data, PNode& head, PNode& tail);

//void show1(PNode head) FIX ME некорректное название
void show_initial_queue(PNode head);

//void del(int m, PNode& head) FIX ME некорректное название
void delete_n_elements(int n, PNode& head);

//void show2(PNode head) FIX ME некорректное название
void show_new_queue(PNode head);

PNode input(int& n);

#endif
