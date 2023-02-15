#include <iostream>
#include <string>
#include <vector>
#include <memory>

/*
 *  1
 * Для реализации связей между элементами списка/дерева выберите наиболее подходящий из умных указателей
 * (unique_ptr, shared_ptr или weak_ptr).
 * Разработать класс стека с операциями вставки и извлечения элемента (push и pop)
 *
 *  2
 * реализовать класс, наполнить его полями и методами. Использовать в реализации умные указатели.
 * Протестировать в случаях, где вероятна утечка памяти
 * (досрочный выход с помощью return или генерации исключения, циклическая зависимость указателей)
 * Класс Студент
 */
using namespace std;

#define SIZE 10

// создание шаблона класса stack

template <class StackType> class stack
{
    ///stackNode
    class stackNode
    {   StackType data;			    // данные ячейки
        weak_ptr<stackNode> m_prev; //указатель на next
    public:
        stackNode(StackType data, shared_ptr<stackNode> &prevNode) {
            this->data = data;
            if(prevNode){
                m_prev = prevNode;
            }
        };

        stackNode(StackType input) {
            this->data = data;
        };
        ~stackNode() {
            cout << "destoyed elem: " << data << endl;
        };

        // используем метод lock() для конвертации std::weak_ptr в std::shared_ptr
        shared_ptr<stackNode> getPrev() const { return m_prev.lock(); }
        StackType getData() const { return data; }
    };
    vector<shared_ptr<stackNode>> stack_vec;
    weak_ptr<stackNode> tail;   //указатель на последний
    weak_ptr<stackNode> current;
    int tos;			// индекс вершины стека
public:
    void init() {tos = 0;}	     // инициализация стека
    void push(StackType ob);	// поместить объект в стек
    StackType pop();	                // извлечь объект из стека
};
/*
template <class StackType> class stack
{
    ///stackNode
    class stackNode
    {   StackType data;			    // данные ячейки
        weak_ptr<stackNode> m_prev; //указатель на next
    public:
        stackNode(StackType data, shared_ptr<stackNode> &prevNode) {
            this->data = data;
            if(prevNode){
                m_prev = prevNode;
            }
        };

        stackNode(StackType input) {
            this->data = data;
        };
        ~stackNode() {
            cout << "destoyed elem: " << data << endl;
        };

        // используем метод lock() для конвертации std::weak_ptr в std::shared_ptr
        shared_ptr<stackNode> getPrev() const { return m_prev.lock(); }
        StackType getData() const { return data; }
    };
    vector<shared_ptr<stackNode>> stack_vec;
    shared_ptr<stackNode> tail;   //указатель на последний
    //shared_ptr<stackNode> current;
    int tos;			// индекс вершины стека
public:
    void init() {tos = 0;}	     // инициализация стека
    void push(StackType ob);	// поместить объект в стек
    void pop();	                // извлечь объект из стека
};

template <class StackType>
void stack <StackType>:: push(StackType ob)
{ if (tos == SIZE)
    { cout << "Stack is full" << endl;
        return;
    }
    if(tos == 0) {
        tail = make_shared<stackNode>(ob);
        //current = tail;
        //auto elem = make_shared<stackNode>(ob);
        //stack_vec.push_back(make_shared<stackNode>(ob));
    }
    else {
        auto temp = tail->getPrev();
        tail = make_shared<stackNode>(ob, temp);
        //tail = current;
        //stack_vec.push_back(make_shared<stackNode>(ob, stack_vec.back()));
    }
    tos++;
}

template <class StackType>
void stack < StackType>:: pop()
{ if (tos == 0)
    { cout << "Stack is empty" << endl; }
    tos--;
    tail = tail->getPrev();
    //auto elem = stack_vec.back()->getData();

    //stack_vec.pop_back();
}
*/
template <class StackType>
void stack <StackType>:: push(StackType ob)
{ if (tos == SIZE)
    { cout << "Stack is full" << endl;
        return;
    }
    if(tos == 0)
        //auto elem = make_shared<stackNode>(ob);
        stack_vec.push_back(make_shared<stackNode>(ob));
    else
        stack_vec.push_back(make_shared<stackNode>(ob, stack_vec.back()));
    tos++;
}

template <class StackType>
StackType stack < StackType>:: pop()
{ if (tos == 0)
    { cout << "Stack is empty" << endl;
        return 0;
    }
    tos--;
    auto elem = stack_vec.back()->getData();
    stack_vec.pop_back();
    return elem;
}


int main(){
    int i;

    // стек типа int
    stack <int> st_int;
    st_int.init();

    for (i = 0; i < 8; i++)
        st_int.push(i * 10);
    for (i = 0; i < 8; i++)
        st_int.pop();
    cout << endl;


    // стек типа double
    stack <double> st_fl;
    st_fl.init();

    for (i = 0; i < 5; i++)
        st_fl.push(i * 2.5);
    for (i = 0; i < 5; i++) {
        st_fl.pop();
        //cout << endl;
    }
    return 0;
}