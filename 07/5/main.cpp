#include "containers.h"

int main() {
    //setlocale(LC_ALL, "Russian"); не разрешено
    int n1, n2;
    deque <int> my_deque;
    list <int> my_list;
    cout << "Введите размерность дека n1 (n1 >= 5): ";
    cin >> n1;
    Input(my_deque, n1);
    cout << "Введите размерность списка n2 (n2 >= 5): ";
    cin >> n2;
    Input(my_list, n2);
    cout << "Изначальное содержимое контейнеров." << endl;
    cout << "Дек: ";
    PrintElements(my_deque);
    cout << "Список: ";
    PrintElements(my_list);
    InsertElements(my_deque, my_list);
    cout << "Изменённое содержание контейнеров." << endl;
    cout << "Дек: ";
    PrintElements(my_deque);
    cout << "Список: ";
    PrintElements(my_list);
    return 0;
}
