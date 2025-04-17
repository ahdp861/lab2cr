
/*
 *Дан циклический двусвязный линейный список и указатель первый     FIX ME задание не по шаблону
 *элемент этого списка. Необходимо удалить в списке все элементы, у которых правый и
 *левый сосед совпадают. Если таких элементов нет, то оставить список без изменений.
 *Первый и последний элементы считать соседями. В результате вернуть ссылку на
 *последний элемент полученного списка.
 *
 *Все динамические структуры данных реализовывать через классы. Не использовать STL.
 *Для каждой динамической структуры должен быть предусмотрен стандартный
 *набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно наличие
 *дружественного интерфейса. Ввод данных с клавиатуры.
 */

#include <iostream>
using namespace std;

class Node
{
public:
    int y;
    //Node* Next; FIX ME некорректное название
    //Node* Prev;
    Node* next;
    Node* previous;
    Node(int x) : y(x), next(NULL), previous(NULL) {}
};
class LinkedList
{
public:
    //Node* Head; FIX ME некорректное название
    //Node* Tail;
    Node* head;
    Node* tail;
    LinkedList() : head(NULL), tail(NULL) {}
};

//void AddLast(LinkedList& s, int x) FIX ME некорректное название
void add_last(LinkedList& list, int x)
{
    //Node* NewNode = new Node(x); FIX ME некорректное название
    Node* new_node = new Node(x);
    new_node->next = NULL;
    new_node->previous = list.tail;
    //if (list.tail == NULL) list.head = new_node; FIX ME нельзя однострочные блоки
    //else list.tail->next = new_node;
    if (list.tail == NULL) {
        list.head = new_node;
    }
    else {
        list.tail->next = new_node;
    }
    list.tail = new_node;
    list.tail->next = list.head;
    list.head->previous = list.tail;
}
//void F(LinkedList& list) FIX ME некорректное название
void do_something(LinkedList& list)
{
    //if (list.head == NULL) return;   FIX ME нельзя однострочные блоки
    if (list.head == NULL) {
        return;
    }
    //Node* MyNode = list.head; FIX ME некорректное название
    //Node* Next1 = NULL;   FIX ME некорректное название
    Node* my_node = list.head;

    do {
        next_temp = my_node->next;
        if ((my_node->previous->y == my_node->next->y) && (my_node->previous!= my_node->next))
        {
            if (my_node == list.head && my_node == list.tail)
            {
                delete my_node;
                list.head = NULL;
                list.tail = NULL;
                break;
            }
            else if (my_node == list.head)
            {
                list.head = my_node->next;
            }
            my_node->previous->next = my_node->next;
            my_node->next->previous = my_node->previous;
            delete my_node;
            my_node = next_temp->previous;
        }
        else {
            my_node = next_temp;
        }
    } while (my_node != list.head);
}
//void Show(LinkedList& list) FIX ME некорректное название
void show_list(LinkedList& list)
{
    if (list.head == NULL)
    {
        cout << "Список пуст" << endl;
        return;
    }
    Node* my_node = list.head;
    do
    {
        cout << my_node->y << " ";
        my_node = my_node->next;
    } while (my_node != list.head);
    cout << endl;
}

//void Clear(LinkedList& list) FIX ME некорректное название
void clear_list(LinkedList& list)
{
    if (list.head == NULL)
        return;
    Node* my_node = list.head;
    do
    {
        //Node* Temp = my_node; FIX ME некорректное название
        Node* temporary_node = my_node;
        my_node = my_node->next;
        delete temporary_node;
    } while (my_node != list.head);
    list.head = NULL;
    list.tail = NULL;
}

LinkedList input() {
    LinkedList spisok;
    int n, x;
    cout << "Введите количество чисел, которые необходимо записать в список: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Ошибка." << endl;
        return 1;
    }
    for (int i = 0; i < n;i++)
    {
        cout << "Введите " << i + 1 << " число: ";
        cin >> x;
        add_last(spisok, x);
    }
    return spisok;
}

int main()
{
    //setlocale(LC_ALL, "Russian"); FIX ME не разрешено
    LinkedList spisok = input();
    /*int n, x;
    cout << "Введите количество чисел, которые необходимо записать в список: "; FIX ME перенести из main
    cin >> n;
    if (n <= 0)
    {
        cout << "Ошибка." << endl;
        return 1;
    }
    for (int i = 0; i < n;i++)
    {
        cout << "Введите " << i + 1 << " число: ";
        cin >> x;
        add_last(spisok, x);
    }*/
    cout << "Исходный список: ";
    show_list(spisok);
    do_something(spisok);
    cout << "Изменённый список: ";
    show_list(spisok);
    clear_list(spisok);
    return 0;
}
