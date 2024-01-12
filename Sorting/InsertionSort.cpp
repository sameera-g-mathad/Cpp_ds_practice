#include <iostream>

using namespace std;

template <class T>
class InsertionSort
{
    T *a;
    int size;
    int length;
    void swap(int i, int j)
    {
        T temp = this->a[i];
        this->a[i] = this->a[j];
        this->a[j] = temp;
    }

public:
    InsertionSort(int size)
    {
        this->size = size;
        this->length = 0;
        this->a = new T[this->size];
    }
    void set(T val)
    {
        this->a[this->length++] = val;
    }
    void sort()
    {
        for (int i = 1; i < this->length; i++)
        {
            int j = i;
            while (j > 0 && this->a[j - 1] > this->a[j])
            {

                swap(j - 1, j);
                j--;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < this->length; i++)
        {
            cout << this->a[i] << " ";
        }
    }
};

int main()
{
    InsertionSort<int> ins(10);
    ins.set(3);
    ins.set(1);
    ins.set(10);
    ins.set(7);
    ins.set(9);
    ins.set(8);
    ins.set(5);
    ins.sort();
    ins.display();
    return 0;
}