#include<iostream>

using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data=data;
        this->next = NULL;
    }
};
template<class T>
class LinkedList{
    LinkedList(){
    Node<int> *head = new Node<int>(0);
    Node<T> *first = head->next;
    }
};


int main()
{
    return 0;
}