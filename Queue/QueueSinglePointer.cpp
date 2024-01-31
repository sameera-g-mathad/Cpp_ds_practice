#include <iostream>

using namespace std;

template <class T>
class QueueSinglePointer
{
    int size;
    int rear;
    T *a;

public:
    QueueSinglePointer(int size)
    {
        this->size = size;
        this->rear = -1;
        this->a = new T[this->size];
    }
    bool queue_full()
    {
        return ((this->rear + 1) == this->size);
    }
    void enque(T data)
    {
        if (queue_full())
        {
            cout << " Queue full \n";
            return;
        }
        this->a[++this->rear] = data;
    }
    void display()
    {
        cout << '\n';
        for (int i = 0; i <= this->rear; i++)
        {
            cout << this->a[i] << " ";
        }
        cout << '\n';
    }
    int dequeue()
    {
        int i = 0;
        while (i < this->rear)
        {
            this->a[i] = this->a[i + 1];
            i++;
        }
        return i;
    }
    int length()
    {
        return this->rear + 1;
    }
};

int main()
{
    QueueSinglePointer<const char *> qsp(10);
    qsp.enque("sameer");
    qsp.enque("swathi");
    qsp.enque("sushma");
    qsp.enque("kishore");
    int shifts = qsp.dequeue();
    qsp.display();
    cout << "It took " << shifts << " shifts for dequeue " << qsp.length() << " which is not efficient\n";
    cout << " This shows queue needs two pointers";
    return 0;
}