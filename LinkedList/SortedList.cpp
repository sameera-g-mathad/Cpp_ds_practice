#include <iostream>

using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
template <class T>
class SortedList
{
    Node<T> *first, *last;
    int counter;

public:
    SortedList()
    {
        first = NULL;
        last = first;
        counter = 0;
    }
    void insert(T data)
    {
        Node<T> *new_node = new Node<T>(data);
        if (!first)
        {
            first = new_node;
            last = first;
            counter++;
            return;
        }
        if (new_node->data <= first->data)
        {
            new_node->next = first;
            first = new_node;
            new_node = NULL;
            counter++;
            return;
        }
        if (new_node->data >= last->data)
        {
            last->next = new_node;
            last = new_node;
            new_node = NULL;
            counter++;
            return;
        }
        Node<T> *current = first, *previous = first;
        while (current != last && current->data < new_node->data)
        {
            previous = current;
            current = current->next;
        }
        new_node->next = current;
        previous->next = new_node;
        previous = current = new_node = NULL;
        counter++;
        return;
    }
    void display()
    {
        Node<T> *traverser = first;
        while (traverser->next)
        {
            cout << traverser->data << " -> ";
            traverser = traverser->next;
        }
        cout << traverser->data << endl;
        cout << counter;
        traverser = NULL;
        cout << endl;
    }
    void reverse()
    {
        Node<T> *previous=NULL,*current=NULL,*further=first;
        while(further)
        {
            current = further;
            further = further->next;
            current.next = previous;
            previous = current;
        }
        first = previous;
    }
};

int main()
{
    SortedList<float> slist;
    slist.insert(1.1);
    slist.insert(1.7);
    slist.insert(1.1);
    slist.insert(2.3);
    slist.insert(1.0);
    slist.display();
    return 0;
}