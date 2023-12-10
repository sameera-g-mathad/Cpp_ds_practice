#include<iostream>

using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node * next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
template<typename T>
class LinkedList{
    public:
    Node<T> *first,*last;
    LinkedList(T *a,int length)
    {
        first = NULL;
        // You can initialize last to first here, but when first is assigned to new variable, 
        //last must again point to first as in the code below
        //last = first;
        if(first == NULL && length>0)
        {
            first = new Node<T>(a[0]);
            // necessary
            last = first;
        }
        for(int i=1;i<length;i++)
        {
            Node<T> * new_node = new Node<T>(a[i]);
            last->next = new_node;
            last = new_node;
            new_node = NULL;
        } 
    }
    Node<T> *returnFirst()
    {
        return first;
    }
    void display()
    {
        Node<T> *traverser=first;
        while(traverser)
        {
            cout<<traverser->data<<" ";
            traverser = traverser->next;
        }
        cout<<'\n';
        traverser = NULL;
    }
    void display_forward_recursion(Node<T> *traverser)
    {
        if(!traverser)
        {
            cout<<'\n';
            return;
        }
        cout<<traverser->data<<" ";
        display_forward_recursion(traverser->next);
    }
    void display_backward_recursion(Node<T> *traverser)
    {
        if(!traverser)
        {
            return;
        }    
        display_backward_recursion(traverser->next);
        cout<<traverser->data<<' ';
    }
    int count_node()
    {
        int count=0;
        Node<T> *traverser = first;
        while(traverser)
        {
            count++;
            traverser=traverser->next;
        }
        traverser = NULL;
        return count;
    }
    int count_node_recursive(Node<T> *traverser)
    {
        if(!traverser)
            return 0;
        return count_node_recursive(traverser->next)+1;
    }
    T max_node_value()
    {
        T max = 0;
        Node<T> *traverser = first;
        while(traverser)
        {
            if(max<traverser->data)
            {
                max = traverser->data;
            }
            traverser=traverser->next;
        }
        return max;
    }
    T max_node_recursive(Node<T> *traverser)
    {
        if(!traverser)
        {
            return 0;
        }
        T x = max_node_recursive(traverser->next);
        return x>traverser->data ? x : traverser->data;
    }
};

int main()
{
    cout<<"Enter length for number of nodes from 1 to length\n";
    int length;
    cin>>length;
    int array[length];
    cout<< "Enter elements of array\n";
    for(int i=0;i<length;i++)
    {
        cin>>array[i];
    }
    LinkedList<int> list(array,length);
    //list.display();
    Node<int> *p_dis_rec = list.returnFirst();
    //list.display_forward_recursion(p_dis_rec);
    //list.display_backward_recursion(p_dis_rec);
    cout<<"Number of nodes is "<<list.count_node()<<endl;
    cout<<"Number of nodes is "<<list.count_node_recursive(p_dis_rec)<<endl;
    cout<<"Max element in the list is "<<list.max_node_recursive(p_dis_rec)<<endl;
    return 0;
}