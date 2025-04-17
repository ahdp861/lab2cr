/* 
Дано число N (> 0) и указатели P1 и P2 на начало и конец непустой очереди. Извлечь
из очереди N начальных элементов и вывести их значения (если очередь содержит менее N
элементов, то извлечь все ее элементы). Вывести также новые адреса начала и конца очереди
(для пустой очереди дважды вывести nullptr). После извлечения элементов из очереди
освобождать память, которую они занимали.


Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.



В заданиях данной подгруппы структура «очередь» (queue) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Началом
очереди («головой», head) считается первый элемент цепочки, концом («хвостом», tail) — ее
последний элемент. Для возможности быстрого добавления в конец очереди нового элемента
удобно хранить, помимо указателя на начало очереди, также и указатель на ее конец. В случае
пустой очереди указатели на ее начало и конец полагаются равными nullptr. Как и для стека,
значением элемента очереди считается значение его поля Data.


*/


//# include <windows.h> FIX ME ненужный include
# include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
};
typedef Node* PNode;

//void add(int data, PNode& Head, PNode& tail) FIX ME некорректное название
void add(int data, PNode& head, PNode& tail)
{
	//PNode Temp; FIX ME некорректное название
	PNode temporary_node;
	if (head == NULL)
	{
		head = new Node;
		tail = head;
		head->next = NULL;

	}
	else
	{
		temporary_node = new Node;
		tail->next = temporary_node;
		tail = temporary_node;
		tail->next = NULL;
	}
	tail->data = data;
}
 
//void show1(PNode head) FIX ME некорректное название
void show_first_element(PNode head)
{
	PNode temporary_node = head;
	cout << endl << "Исходный адрес первого элемента: " << head << " " << head->data;

	cout << endl << "Исходная очередь: ";
	while (temporary_node != nullptr) 
	{
		cout << temporary_node->data << " ";
		temporary_node = temporary_node->next;
	}

	PNode last = head;
	while (last->next != nullptr)
	{
		last = last->next;
	}

	cout << endl << "Исходный адрес последнего элемента: " << last << " " << last->data << endl;
}



//void del(int m, PNode& head) FIX ME некорректное название
void delete_node(int m, PNode& head)
{
	PNode temporary_node;
	for (int i = 0; i < m; i++)
	{
		temporary_node = head;
		cout << temporary_node->data << " " << temporary_node->next << " ";
		head = head->next;
		delete temporary_node;
		cout << endl;
	}
	cout << endl;
}

//void show2(PNode head) FIX ME некорректное название
void show_new_queue(PNode head)
{
	PNode temporary_node = nullptr;
	PNode temp2 = head;
	if (head == nullptr)
	{
		cout << "Очередь после удаления элементов оказалась пустой" << endl;
		//int* ptr = nullptr; FIX ME некорректное название
		int* pointer = nullptr;
		cout << "Начало очереди: " << pointer << endl;
		cout << "Конец очереди: " << pointer << endl;
	}
	else
	{
		cout << "Новое начало очереди: " << temp2 << " " << temp2->data << endl;
		cout << "Оставшиеся элементы очереди: ";
		while (head != nullptr)
		{
			temporary_node = head;	
			cout << temporary_node->data << " ";
			head = head->next;
			//delete temporary_node;
		}
		cout << endl << "Новый конец очереди: " << temporary_node << " " << temporary_node->data << endl;
	}	
}

PNode input() {
	int m, n;
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
	for (int i = 0; i < m; i++)
	{
		int j;
		cin >> j;
		add(j, p1, p2);
	}
	return p1;
}


int main()
{
	//SetConsoleCP(1251); FIX ME не разрешено
	//SetConsoleOutputCP(1251);
	/*int m, n;		FIX ME перенести в функцию
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
	for (int i = 0; i < m; i++)
	{
		int j;
		cin >> j;
		add(j, p1, p2);
	}*/
	PNode p1 = input();
	cout << endl << endl << "Введите число n(n>0) - количество элементов" << endl;
	cout << "очереди, которые нужно извлечь из очереди: ";
	cin >> n;
	show_first_element(p1);
	delete_node(n, p1);
	show_new_queue(p1);
	return 0;
}
