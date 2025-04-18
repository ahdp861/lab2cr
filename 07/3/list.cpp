#include "list.h"

//void add(int data, PNode& Head, PNode& LastNode) FIX ME некорректное название
void AddNode(int data, PNode& head, PNode& last_node) {
  PNode temporary_node;
  if (head == nullptr) {
    head = new Node;
    last_node = head;
    head->next = nullptr;
  }
  else {
    temporary_node = new Node;
    last_node->next = temporary_node;
    last_node = temporary_node;
    last_node->next = nullptr;
  }
  last_node->x = data;
}

//void Show(PNode& Head) FIX ME некорректное название
void Show(PNode& head) {
  //PNode Mynode = head; FIX ME некорректное название
  PNode my_node = head;
  cout << "Все числа из списка: ";

  while (my_node != nullptr) {
    cout << my_node->x << " ";
    my_node = my_node->next;
  }
}

//void addafter(int data, PNode& head) FIX ME некорректное название
void AddAfter(int data, PNode& head) {
  //PNode Temp = head; FIX ME некорректное название
  PNode temporary_node = head;
  PNode my_node;
  int count = 1;
  while (temporary_node != nullptr) {
    ++count; // FIX ME префиксная запись
    if (count == 4) {
      my_node = new Node;
      my_node->x = data;
      my_node->next = temporary_node->next;
      temporary_node->next = my_node;
      count = 0;
    }
    temporary_node = temporary_node->next;
  }
}

//void showafter(PNode& head) FIX ME некорректное название
void ShowAfter(PNode& head) {
  PNode my_node = head;
  cout << endl;
  cout << "Все числа из измененного списка: ";
  while (my_node != nullptr) {
    cout << my_node->x << " ";
    my_node = my_node->next;
  }
  cout << endl;
}

//PNode showlast(PNode& head) FIX ME некорректное название
PNode ShowLast(PNode& head) {
  //PNode my_node_2 = head; FIX ME некорректное название
  PNode my_node_2 = head;
  while (my_node_2 != nullptr && my_node_2->next != nullptr) {
    my_node_2 = my_node_2->next;
  }
  return my_node_2;
}

//PNode find(PNode head, int data) FIX ME некорректное название
PNode FindNode(PNode head, int data) {
  //PNode node = head; FIX ME некорректное название
  PNode node = head;
  while (node && node->x != data)
    node = node->next;
  return node;
}

//void DeleteNode(PNode& head, PNode OldNode) FIX ME некорректное название
void DeleteNode(PNode& head, PNode old_node) {
  PNode node = head;
  if (head == old_node)
    head = old_node->next;  // удаляем первый элемент 
  else {
    while (node->next != old_node) // ищем элемент 
      node = node->next;
    node->next = old_node->next;
  }
  delete old_node; // освобождаем память 
}

PNode Input() {
  PNode list = NULL;
  PNode last_node = NULL;
  cout << "Добро пожаловать!" << endl;
  cout << "Перед нами задача: " << endl;
  cout << "Дан односвязный линейный список" << endl;
  cout << "Необходимо вставить значение M после каждого третьего элемента списка," << endl;
  cout << "-------------------------------------------------------------------" << endl;
  cout << "Вам необходимо ввести два значения: " << endl;
  cout << "1. n(n>=3) - количество элементов в списке" << endl;
  cout << "2. m - число, которое мы будем вставлять. " << endl;
  cout << "Затем через пробел ввести элементы списка, количество которых будет совпадать с тем, что вы ввели ранее," << endl;
  cout << "После мы выведем полученный результат на экран и ссылку на последний элемент. " << endl;
  cout << "--------------------------------------------------------" << endl;
  cout << "Введите число(БОЛЬШЕ 3) - количество элементов в массиве: ";
  int n, x, m;
  cin >> n;
  cout << "Введите " << n << " элементов списка ";
  for (int i = 1; i <= n; i++) {
    cin >> x;
    AddNode(x, list, last_node);
  }
  cout << endl;
  return list;
}
