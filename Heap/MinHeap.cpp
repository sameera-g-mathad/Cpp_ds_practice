#include <iostream>
using namespace std;

class MinHeap
{
    int *a, length, size;
    void swap(int i, int j)
    {
        int temp = this->a[i];
        this->a[i] = this->a[j];
        this->a[j] = temp;
    }
    void minHeap(int index)
    {
        while (index > 0)
        {
            int parent = int((index - 1) / 2);
            if (this->a[parent] > this->a[index])
            {
                swap(parent, index);
            }
            index = parent;
        }
    }

public:
    MinHeap(int size)
    {
        this->size = size;
        this->length = 0;
        this->a = new int[this->size];
    }
    void assign(int data)
    {
        this->a[this->length++] = data;
    }
    void display()
    {
        for (int i = 0; i < this->length; i++)
        {
            cout << this->a[i] << " ";
        }
        cout << '\n';
    }

    void createHeap()
    {
        for (int i = 1; i < this->length; i++)
        {
            this->minHeap(i);
        }
    }
};

int main()
{
    int size;
    cout << "Enter size" << endl;
    cin >> size;
    MinHeap mH(size);
    cout << "Enter elements" << endl;
    for (int i = 0; i < size; i++)
    {
        int data;
        cin >> data;
        mH.assign(data);
    }
    mH.display();
    mH.createHeap();
    mH.display();
    return 0;
}