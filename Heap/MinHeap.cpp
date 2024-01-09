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
    void deleteHeap(int n)
    {
        swap(0, n);
        int i = 0, j = 2 * i + 1;
        while (j < n - 1)
        {
            if (this->a[j] > this->a[j + 1])
            {
                j = j + 1;
            }
            if (this->a[i] > this->a[j])
            {
                swap(i, j);
                i = j;
                j = 2 * i;
            }
            else
                break;
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
        cout << '\n';
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
    void heapsort()
    {
        for (int i = this->length - 1; i > 0; i--)
        {
            deleteHeap(i);
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
    mH.createHeap();
    mH.heapsort();
    cout << "Elements in non-increasing order:\n";
    mH.display();
    return 0;
}