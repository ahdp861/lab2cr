/*Дан односвязный линейный список и указатель на голову списка P1. Необходимо FIX ME не по шаблону
 *вставить значение M после каждого второго элемента списка, и вывести ссылку на последний
 *элемент полученного списка P2.
 *
 *Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
 *добавления/удаления/вывода элементов.
 *Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
 *
 */



//# include <windows.h> FIX ME ненужный include
# include <iostream>
using namespace std;

class Node{
public:
	int x;
	Node* next;
};
typedef Node* PNode;

//void add(int data, PNode& Head, PNode& LastNode) FIX ME некорректное название
void add_node(int data, PNode& head, PNode& last_node)
{
	PNode temporary_node;
	if (head == nullptr)
	{
		head = new Node;
		last_node = head;
		head->next = nullptr;
	}
	else
	{
		temporary_node = new Node;
		last_node->next = temporary_node;
		last_node = temporary_node;
		last_node->next = nullptr;
	}
	last_node->x = data;
}

//void Show(PNode& Head) FIX ME некорректное название
void show(PNode& head)
{
	//PNode Mynode = head; FIX ME некорректное название
	cout << "Все числа из списка: ";

	while (my_node != nullptr)
	{
		cout << my_node->x << " ";
		my_node = my_node->next;
	}

}

//void addafter(int data, PNode& head) FIX ME некорректное название
void add_after(int data, PNode& head)
{
	//PNode Temp = head; FIX ME некорректное название
	PNode temporary_node = head;
	PNode my_node;
	int count = 1;
	while (temporary_node != nullptr)
	{
		//count++; FIX ME префиксная запись
		++count;
		if (count == 4)
		{
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
void show_after(PNode& head)
{
	PNode my_node = head;
	cout << endl;
	cout << "Все числа из измененного списка: ";
	while (my_node != nullptr)
	{
		cout << my_node->x << " ";
		my_node = my_node->next;
		
	}
	cout << endl;
}

//PNode showlast(PNode& head) FIX ME некорректное название
PNode show_last(PNode& head)
{
	//PNode my_node_2 = head; FIX ME некорректное название
	PNode my_node_2 = head;
	while (my_node_2 != nullptr && my_node_2->next != nullptr)
	{
		my_node_2 = my_node_2->next;
	}
	return my_node_2;
}

//PNode find(PNode head, int data) FIX ME некорректное название
PNode find_node(PNode head, int data)
{
	//PNode node = head; FIX ME некорректное название
	PNode node = head;
	while (node && node->x != data)
		node = node->next;
	return node;
}


//void DeleteNode(PNode& head, PNode OldNode) FIX ME некорректное название
void delete_node(PNode& head, PNode old_node)
{
	PNode node = head;
	if (head == old_node)
		head = old_node->next;  // удаляем первый элемент 
	else
	{
		while (node->next != old_node) // ищем элемент 
			node = node->next;
		node->next = old_node->next;
	}
	delete old_node; // освобождаем память 
}

PNode input() {
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
	int n, x, m;;
	cin >> n;
	cout << "Введите " << n << " элементов списка ";
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		add(x, list, last_node);
	}
	cout << endl;
	return list;
}

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
	}break;

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
