#include "queue.h"

//void add(int data, PNode& Head, PNode& tail) FIX ME некорректное название
void add(int data, PNode& head, PNode& tail) {
  //PNode Temp; FIX ME некорректное название
  PNode temporary_node;
  if (head == NULL) {
    head = new Node;
    tail = head;
    head->next = NULL;
  }
  else {
    temporary_node = new Node;
    tail->next = temporary_node;
    tail = temporary_node;
    tail->next = NULL;
  }
  tail->data = data;
}

//void show1(PNode head) FIX ME некорректное название
void show_initial_queue(PNode head) {
  PNode temporary_node = head;
  cout << endl << "Исходный адрес первого элемента: " << head << " " << head->data;

  cout << endl << "Исходная очередь: ";
  while (temporary_node != nullptr) {
    cout << temporary_node->data << " ";
    temporary_node = temporary_node->next;
  }

  PNode last = head;
  while (last->next != nullptr) {
    last = last->next;
  }

  cout << endl << "Исходный адрес последнего элемента: " << last << " " << last->data << endl;
}

//void del(int m, PNode& head) FIX ME некорректное название
void delete_n_elements(int n, PNode& head) {
  PNode temporary_node;
  for (int i = 0; i < n; i++) {
    if (head == nullptr)  // Защита от удаления из пустой очереди
      break;

    temporary_node = head;
    cout << temporary_node->data << " " << temporary_node->next << " ";
    head = head->next;
    delete temporary_node;
    cout << endl;
  }
  cout << endl;
}

//void show2(PNode head) FIX ME некорректное название
void show_new_queue(PNode head) {
  PNode temporary_node = nullptr;
  PNode temp2 = head;
  if (head == nullptr) {
    cout << "Очередь после удаления элементов оказалась пустой" << endl;
    //int* ptr = nullptr; FIX ME некорректное название
    int* pointer = nullptr;
    cout << "Начало очереди: " << pointer << endl;
    cout << "Конец очереди: " << pointer << endl;
  }
  else {
    cout << "Новое начало очереди: " << temp2 << " " << temp2->data << endl;
    cout << "Оставшиеся элементы очереди: ";
    while (head != nullptr) {
      temporary_node = head;
      cout << temporary_node->data << " ";
      head = head->next;
      //delete temporary_node; // Не удаляем здесь, т.к. элементы остаются в очереди
    }
    cout << endl << "Новый конец очереди: " << temporary_node << " " << temporary_node->data << endl;
  }
}

PNode input(int& n) {
  int m;
  PNode p1 = nullptr;
  PNode p2 = nullptr;
  cout << "Добро пожаловать!" << endl;
  cout << "Перед нами новая задача:" << endl;
  cout << "Дано число N (> 0) и указатели P1 и P2 на начало и конец непустой очереди." << endl;
  cout << "Извлечь из очереди N начальных элементов" << endl;
  cout << "---------------------------------------------------------" << endl;
  cout << "Вам необходимо ввести количество элементов очереди и их значения через пробел " << endl;
  cout << "Мы выведем новые адреса начала и конца очереди, извлечем n значений и выведем на экран" << endl;
  cout << endl << endl << "----------------------------------------------------------------------------" << endl;
  cout << "Введите число m - количество элементов очереди: ";
  cin >> m;
  cout << endl << "Введите " << m << " значений элементов очереди через пробел ";
  for (int i = 0; i < m; i++) {
    int j;
    cin >> j;
    add(j, p1, p2);
  }
  cout << endl << endl << "Введите число n(n>0) - количество элементов" << endl;
  cout << "очереди, которые нужно извлечь из очереди: ";
  cin >> n;
  return p1;
}
