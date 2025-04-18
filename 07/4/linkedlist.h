#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
public:
    int y;
    //Node* Next; FIX ME некорректное название
    //Node* Prev;
    Node* next;
    Node* previous;
    Node(int x) : y(x), next(NULL), previous(NULL) {}
};

class LinkedList {
public:
    //Node* Head; FIX ME некорректное название
    //Node* Tail;
    Node* head;
    Node* tail;
    LinkedList() : head(NULL), tail(NULL) {}
};

//void AddLast(LinkedList& s, int x) FIX ME некорректное название
void add_last(LinkedList& list, int x);

//void F(LinkedList& list) FIX ME некорректное название
void do_something(LinkedList& list);

//void Show(LinkedList& list) FIX ME некорректное название
void show_list(LinkedList& list);

//void Clear(LinkedList& list) FIX ME некорректное название
void clear_list(LinkedList& list);

LinkedList input();

#endif
