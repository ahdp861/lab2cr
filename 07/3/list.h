#ifndef LIST_H
#define LIST_H

//# include <windows.h> FIX ME ненужный include
#include <iostream>

using namespace std;

class Node {
public:
  int x;
  Node* next;
};
typedef Node* PNode;

//void add(int data, PNode& Head, PNode& LastNode) FIX ME некорректное название
void AddNode(int data, PNode& head, PNode& last_node);

//void Show(PNode& Head) FIX ME некорректное название
void Show(PNode& head);

//void addafter(int data, PNode& head) FIX ME некорректное название
void AddAfter(int data, PNode& head);

//void showafter(PNode& head) FIX ME некорректное название
void ShowAfter(PNode& head);

//PNode showlast(PNode& head) FIX ME некорректное название
PNode ShowLast(PNode& head);

//PNode find(PNode head, int data) FIX ME некорректное название
PNode FindNode(PNode head, int data);

//void DeleteNode(PNode& head, PNode OldNode) FIX ME некорректное название
void DeleteNode(PNode& head, PNode old_node);

PNode Input();

#endif
