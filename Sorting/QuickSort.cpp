#include <iostream>

using namespace std;

template <class T>
class QuickSort
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
    int partition_pivot(int low, int high)
    {
        int i, j, pivot;
        i = pivot = low;
        j = high;
        while (i < j)
        {
            do
            {
                i++;
            } while (this->a[pivot] >= this->a[i]);
            do
            {
                j--;
            } while (this->a[pivot] < this->a[j]);
            if (i < j)
            {
                swap(i, j);
            }
        }
        swap(pivot, j);
        // Return the new position of the pivot
        return j;
    }

public:
    QuickSort(int size)
    {
        this->size = size;
        this->length = 0;
        this->a = new T[this->size];
    }
    void set(T val)
    {
        this->a[this->length++] = val;
    }

    void sort(int low, int high)
    {
        if (low < high)
        {
            int pivot = this->partition_pivot(low, high);
            this->sort(low, pivot);
            this->sort(pivot + 1, high);
        }
    }
    int getLength()
    {
        return this->length;
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
};

int main()
{
    QuickSort<int> quick(10);
    quick.set(50);
    quick.set(10);
    quick.set(30);
    quick.set(40);
    quick.set(50);
    quick.set(20);
    quick.set(60);
    quick.sort(0, quick.getLength() - 1);
    quick.display();
    return 0;
}