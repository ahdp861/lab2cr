#include "linkedlist.h"

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
