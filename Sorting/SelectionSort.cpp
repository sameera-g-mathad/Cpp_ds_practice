#include <iostream>

using namespace std;

template <class T>
class SelectionSort
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
    SelectionSort(int size)
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
        for (int i = 0; i < this->length - 1; i++)
        {
            int k = i;
            for (int j = i; j < this->length; j++)
            {
                if (this->a[k] > this->a[j])
                {
                    k = j;
                }
            }
            swap(i, k);
                }
    }
    void display()
    {
        for (int i = 0; i < this->length; i++)
        {
            cout << this->a[i] << " ";
        }
        cout << '\n';
    }
};

int main()
{
    SelectionSort<int> sel(10);
    sel.set(3);
    sel.set(1);
    sel.set(10);
    sel.set(7);
    sel.set(9);
    sel.set(8);
    sel.set(5);
    sel.sort();
    sel.display();
    return 0;
}