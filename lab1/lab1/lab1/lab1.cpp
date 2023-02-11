//#include "stdafx.h"
#include <iostream>
#include <string> 
#include <conio.h>

using namespace std;

template <class T> class List
{
public:
    List();

    void push_back(T data);
    void pop();
    int GetSize() { return size; }

    T& operator[](const int index); //перегрузка оператора для доступа к данным с возможностью изменения их

private:
    template <class T> class Node
    {
    public:
        Node* pNext;
        T data;
        Node(T data=T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        };
    };

    int size;
    Node<T>* head;
    Node<T>* tail;
};

template <class T> List<T>::List(){
    size = 0;
    head = nullptr;
    tail = head;
}


template <class T> void List<T>::push_back(T data){
    if (head == nullptr) {
        head = new Node<T>(data);
        tail = head;
    }
    else {
        Node<T>* current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
        tail = current->pNext;
    }
    size++;
}

template<class T> void List<T>::pop() {
    if (size == 0) {
        cout << "List is empty" << endl;
    }
    else {
        Node<T>* current = this->head;
        Node<T>* tmp = tail;
        if (head == nullptr) {
            delete(tail);
        }
        else
        while (current->pNext != tail) {
            current = current->pNext;
        }
        current->pNext = nullptr;
        delete(tail);
        size--;
        tail = current;
    }
}

template <class T> T& List<T>::operator[](const int index)
{
    int cntr = 0;
    Node<T>* current = this->head;
    while (current != nullptr) {
        if (cntr == index) {
            return current->data;
        }
        current = current->pNext;
        cntr++;
    }
}


int main(int argc, char* argv[])
{	
    List<int> lst;
    lst.push_back(-1);
    lst.push_back(0);
    lst.push_back(1);
    lst.push_back(2);
    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << endl;
    }
    lst.pop();
    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << endl;
    }
    return 0;
}
