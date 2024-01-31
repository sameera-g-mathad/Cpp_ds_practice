#include <iostream>

using namespace std;

template <class T>
class SingularQueue
{
    int size, rear, front;
    T *queue;

public:
    SingularQueue(int size)
    {
        this->size = size;
        this->rear = this->front = -1;
        this->queue = new T[this->size];
    }
    bool queue_full()
    {
        return (this->rear + 1) == this->size;
    }
    bool queue_empty()
    {
        return this->rear == this->front;
    }
    T dequeue()
    {
        if (queue_empty())
        {
            cout << "Queue is empty\n";
            return 0;
        }
        T deleted_item = this->queue[++this->front];
    }
    void enqueue(T data)
    {
        if (queue_full())
        {
            cout << "Queue is full\n";
            return;
        }
        this->queue[++this->rear] = data;
    }
    void display()
    {
        cout << '\n';
        for (int i = front + 1; i <= this->rear; i++)
        {
            cout << this->queue[i] << " ";
        }
        cout << '\n';
    }
};
int main()
{
    SingularQueue<const char *> sq(5);
    sq.enqueue("sameer");
    sq.enqueue("sushma");
    sq.enqueue("kishore");
    sq.enqueue("swathi");
    sq.enqueue("rashmi");
    sq.enqueue("can you add");
    sq.dequeue();
    sq.display();

    return 0;
}