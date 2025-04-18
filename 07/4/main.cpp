#include "linkedlist.h"

int main() {
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
    ShowList(spisok);
    DoSomething(spisok);
    cout << "Изменённый список: ";
    ShowList(spisok);
    ClearList(spisok);
    return 0;
}
