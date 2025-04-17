/* Элементами контейнеров являются целые числа. Для FIX ME не по шаблону
 *заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
 *для вывода элементов использовать итератор (для вывода элементов в обратном порядке
 *использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
 *Обязательно наличие дружественного интерфейса. Ввод данных организовать
 *разными способами (с клавиатуры, рандом, из файла)
 *
 *Даны дек my_deque и список my_list. Каждый исходный контейнер содержит не менее 5
 *элементов. Вставить перед пятым с конца элементом списка последние 5 элементов дека в
 *обратном порядке. Использовать один вызов функции-члена insert.
 *
 */


#include <ctime>
#include <deque>
#include <list>
#include <fstream>
#include <iostream>
using namespace std;
template <typename container>

//void Input(container& N, int n)//Заполнение контейнеров FIX ME некорректное название
void input(container& container, int container_size)//Заполнение контейнеров
{
    //int m, x; FIX ME некорректное название
    int option, element;
    cout << "Выберете способ заполнения контейнера: " << endl;
    cout << "1)Ввод с клавиатуры." << endl;
    cout << "2)Ввод с помощью рандомайзера." << endl;
    cout << "3)Ввод данных из текстового файла." << endl;
    cin >> option;
    if (container_size < 5)
    {
        cout << "Ошибка. Недопустимый размер." << endl;
        return;
    }
    switch (option)
    {
    case 1:
    {
        //for (int i = 0; i < container_size;i++) FIX ME постфиксная запись
        for (int i = 0; i < container_size;++i)
        {
            cout << "Введите " << i + 1 << " элемент: ";
            cin >> element;
            container.insert(container.end(), element);
        }
        break;
    }
    case 2:
    {
        srand(time(0));
        //for (int i = 0; i < container_size;i++) FIX ME постфиксная запись, нет скобок
        for (int i = 0; i < container_size;++i) {
            container.insert(container.end(), rand() % 101 - 50);
        }
        break;
    }
    case 3:
    {
        ifstream file("a.txt", ios::in);// a.txt {9 3 -44-82 75 2 5 9 -43 74 927 94 -27 3 57 1 0 74 473 84}
        if (!file)
        {
            cout << "Ошибка. Файл не был открыт.";
            return;
        }
        for (int i = 0; i < container_size;i++)
        {
            file >> element;
            container.insert(container.end(), element);
        }
        file.close();
        break;
    }
    default:
    {
        cout << "Ошибка ввода." << endl;
        break;
    }
    }
}
template <typename container>

//void Print(const container& container)//Вывод содержимого контейнеров FIX ME некорректное название
void print_elements(const container& container)
{
    for (auto it = container.begin(); it != container.end(); it++)
        cout << *it << " ";
    cout << endl;
}
//void Insert(deque<int>& D, list<int>& L)//Вставка перед 5 с конца элемента списка последних 5 элементов дека в обратном порядке FIX ME некоректное название
void insert(deque<int>& my_deque, list<int>& my_list)//Вставка перед 5 с конца элемента списка последних 5 элементов дека в обратном порядке
{
    list<int>::iterator it = my_list.end();
    //for (int i = 0; i < 5;i++) FIX ME постфиксная запись, скобки
    for (int i = 0; i < 5;++i) {
        --it;
    }
    //for (int i = 4; i >= 0; i--) FIX ME постфиксная запись, скобки
    for (int i = 4; i >= 0; --i) {
        it = my_list.insert(it, my_deque[my_deque.size() - 1 - i]);
    }
        
}
int main()
{
    //setlocale(LC_ALL, "Russian"); не разрешено
    int n1, n2;
    deque <int> my_deque;
    list <int> my_list;
    cout << "Введите размерность дека n1 (n1 >= 5): ";
    cin >> n1;
    input(my_deque, n1);
    cout << "Введите размерность списка n2 (n2 >= 5): ";
    cin >> n2;
    input(my_list, n2);
    cout << "Изначальное содержимое контейнеров." << endl;
    cout << "Дек: ";
    Print(my_deque);
    cout << "Список: ";
    print_elements(my_list);
    insert(my_deque, my_list);
    cout << "Изменённое содержание контейнеров." << endl;
    cout << "Дек: ";
    print_elements(my_deque);
    cout << "Список: ";
    print_elements(my_list);
    return 0;
}
