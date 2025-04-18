#include "list.h"

int main()
{
  //SetConsoleCP(1251);	FIX ME не разрешено
  //SetConsoleOutputCP(1251);
  /*PNode list = NULL;	FIX ME перенести из main, некорректные названия
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
  int n, x, m;;
  cin >> n;
  cout << "Введите " << n << " элементов списка ";
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    add(x, list, last_node);
  }
  cout << endl;
  */
  PNode list = input();
  cout << "Введите значение m для вставки после каждого третьего элемента: ";
  int m;
  cin >> m;
  cout << endl;
  show(list);
  cout << endl;
  add_after(m, list);
  show_after(list);
  cout << endl;
  PNode last = show_last(list);
  cout << "Ссылка на последний элемент: " << last << " " << last->x;

  int choice;
  cout << endl << "Хотите удалить какой-нибудь элемент?" << endl;
  cout << "Если да, то напишите 1" << endl;
  cout << "Если нет, то напишите 2" << endl;
  cout << "Ваш выбор: ";
  cin >> choice;
  cout << endl;
  switch (choice)
  {
  case 1:
  {
    cout << "Введите число - количество элементов которое вы хотите удалить: ";
    int num;
    cin >> num;
    //for (int i = 0; i < num; i++) FIX ME постфиксная запись
    for (int i = 0; i < num; ++i)
    {
      cout << "Введите значение элемента, который вы хотите удалить: ";
      int x;
      cin >> x;
      PNode p = find_node(list, x);
      cout << endl;
      cout << "Удаление...." << endl;
      delete_node(list, p);
    }
    show(list);
  }
  break;

  case 2:
  {
    {
      cout << "Спасибо за терпение!!!" << endl;
      cout << "До свидания!!!" << endl;
    }
  }
  default:
  {
    cout << "Введено неверное число";
    break;
  }
  }
  return 0;
}
