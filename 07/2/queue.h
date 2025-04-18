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
void AddNode(int data, PNode& head, PNode& tail);

//void show1(PNode head) FIX ME некорректное название
void ShowInitialQueue(PNode head);

//void del(int m, PNode& head) FIX ME некорректное название
void DeleteNElements(int n, PNode& head);

//void show2(PNode head) FIX ME некорректное название
void ShowNewQueue(PNode head);

PNode Input(int& n);

#endif
