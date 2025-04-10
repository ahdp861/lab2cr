/*
Дан указатель P1 на вершину непустого стека. Извлечь из стека первый (верхний)
элемент и вывести его значение D, а также адрес P2 новой вершины стека. Если после
извлечения элемента стек окажется пустым, то положить P2 = nullptr. После извлечения
элемента из стека освободить память, занимаемую этим элементом.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
элемента стека считается значение его поля Data*/






#include <iostream>

using namespace std;

//class stack {       FIX ME нет отступов между блоками кода, табуляция двумя пробелами, некорректное название класса
class Stack {

    private:

        struct Node {
            int d;
            Node* next;
            //Node(int val): d(val), next(nullptr) {} FIX ME некорректное название
            Node(int node_value) : d(node_value), next(nullptr) {}
        };

        Node* p1; //вершина
        //int cnt; FIX ME некорректное название
        int counter;

    public:

        Stack(): p1(nullptr), counter(0){}
        //void add(int x) {   FIX ME некорректное название
        void add_node(int new_node_value) {   
            //Node* newnode = new Node(new_node_value); FIX ME некоректное название
            Node* new_node = new Node(new_node_value);
            new_node->next = p1;
            p1 = new_node;
            //counter++; FIX ME постфиксная запись
            ++counter;
        }

        //void topdel() { //извлечение 1 элемента и его удаление  FIX ME некорректное название
        void delete_top() { //извлечение 1 элемента и его удаление
            //Node* temp = p1; FIX ME некорректное название
            Node* temporary_node = p1;
            cout << "Первый элемент стека:" << endl;
            cout << p1->d << endl;
            if (p1->next == nullptr) {
                p1 = nullptr;
            }
            else {
                p1 = p1->next;
            }
            cout << "Адрес новой вершины p1 после извлечения 1 элемента: " << p1 << endl; // Вывод адреса новой вершины
            if (p1 != nullptr) {
                cout << "Значение новой вершины p1: " << p1->d << endl; // Вывод значения новой вершины
            }
            delete temporary_node;
            //counter--; FIX ME постфиксная запись
            --counter;
            }

    //void show() { FIX ME некорректное название
    void show_stack() {
        //Node* temp = p1; FIX ME некорректное название
        while (temporary_node != nullptr) {
            cout << temporary_node->d << endl;
            temporary_node = temporary_node->next;
        }
    }
};

int main() {

    //Stack Stack; FIX ME некорректное название
    Stack stack;
    setlocale(LC_ALL, "RU");
    cout << "Введите количество элементов стека" << endl;
    //int n; FIX ME некорректное название
    int stack_size;
    cin >> stack_size;;//размер стека FIX ME лишний коммнтарий
    for (int i = 0; i < stack_size; i++) {
        //int num; FIX ME некорректное название
        int node_value;
        cout << "Введите элемент стека" << endl;
        cin >> node_value;
        stack.add_node(node_value);
    }
    cout << "Стек:" << endl;
    stack.show_stack();
    stack.delete_top();
    return 0;
}