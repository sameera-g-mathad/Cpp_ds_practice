#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
template <class T>
class LinkedList
{
private:
    int counter;
    Node<T> *first, *last;

public:
    LinkedList()
    {
        first = NULL;
        last = first;
        counter = 0;
    }
    /*
    # Insert at front = o(1)
    # Insert at last = o(1)
    # Number of pointers = 2 (first, last)
    # New node created = 1 (new_node)
    */
    void insert(T data)
    {
        Node<T> *new_node = new Node<T>(data);
        if (!this->first)
        {
            first = new_node;
            last = first;
        }
        else
        {
            last->next = new_node;
            last = new_node;
            new_node = NULL;
        }
        counter++;
    }
    /*
    # Insert at front = o(1)
    # Insert at last = o(1)
    # Insert at any index = o(n)
    # Number of pointers = 3 (first, last,traverser)
    # New node created = 1 (new_node)
    */
    void insert(int data, int position)
    {
        Node<T> *new_node = new Node<T>(data);
        Node<T> *traverser = first;
        if (position <= 1)
        {
            new_node->next = first;
            first = new_node;
            new_node = NULL;
            counter++;
            return;
        }
        if (position > counter)
        {
            last->next = new_node;
            last = new_node;
            new_node = NULL;
            counter++;
            return;
        }
        for (int i = 1; i < position - 1; i++)
        {
            traverser = traverser->next;
        }
        new_node->next = traverser->next;
        traverser->next = new_node;
        new_node = NULL;
        traverser = NULL;
        counter++;
    }
    int count()
    {
        return counter;
    }
    /*
    'f' --> only display first item o(1)
    'F' --> only display first item o(1)
    'l' --> only display Last item  o(1)
    'L' --> only display Last item  o(1)
    'a' --> o(n)
    */
    void display(char node = 'a')
    {
        Node<T> *traverser = first;
        cout << endl;
        if (node == 'f' || node == 'F')
        {
            cout << first->data << endl;
            return;
        }
        if (node == 'l' || node == 'L')
        {
            cout << last->data << endl;
            return;
        }
        while (traverser)
        {
            cout << traverser->data << " ";
            traverser = traverser->next;
        }
        cout << '\n';
        cout << this->count();
    }
    /*
    Time = o(1) -- always
    Space = o(1)
    pointer = 1 (junk_node)
    */
    T delete_front()
    {
        if (first)
        {
            T data = first->data;
            Node<T> *junk_node = first;
            first = first->next;
            delete junk_node;
            counter--;
            return data;
        }
        return 0;
    }
    /*

    Time = o(n) -- always
    Space = o(1)
    pointer = 1 (junk_node)
    */
    T delete_last()
    {
        if (first == last)
            return 0;
        Node<T> *traverser = first;
        while (traverser->next != last)
        {
            traverser = traverser->next;
        }
        T data = last->data;
        delete last;
        counter--;
        last = traverser;
        last->next = NULL;
        traverser = NULL;
        return data;
    }
    /*
    Time - min[delete_first] --> o(1),max[delete_last] --> o(n)
    Space - o(1)
    */
    T delete_position(int position)
    {
        if (position <= 1)
            return this->delete_front();
        if (position >= counter)
            return this->delete_last();
        Node<T> *traverser = first;
        for (int i = 1; i < position - 1; i++)
        {
            traverser = traverser->next;
        }
        Node<T> *junk_node = traverser->next;
        T data = junk_node->data;
        traverser->next = junk_node->next;
        delete junk_node;
        counter--;
        return data;
    }
};

int main()
{
    LinkedList<char> list;
    list.insert('a');
    list.insert('m');
    list.insert('e');
    list.insert('e');
    list.insert('r');
    list.insert('g');
    list.insert('s', 0);
    list.insert('a', 7);
    list.insert('m', 12);
    list.insert('a', 12);
    list.insert('t', 12);
    list.insert('h', 17);
    list.insert('a', 18);
    list.insert('d', 19);
    list.display();
    list.delete_front();
    list.display();
    list.delete_last();
    list.delete_last();
    list.display();
    list.delete_position(4);
    list.display();
    list.delete_position(-1);
    list.display();
    list.delete_position(12);
    list.display();
    return 0;
}