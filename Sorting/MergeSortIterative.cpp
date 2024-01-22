#include <iostream>

using namespace std;

template <class T>
class MergeSortIterative
{
    T *a;
    int length;
    int size;
    void merge(int low, int mid, int high)
    {
        int i = low, j = mid + 1;
        T *b = new T[high + 1];
        int k = 0;
        while (i <= mid && j <= high)
        {
            if (this->a[i] < this->a[j])
            {
                b[k++] = this->a[i++];
            }
            else if (this->a[i] > this->a[j])
            {
                b[k++] = this->a[j++];
            }
            else
            {
                b[k++] = this->a[i++];
                b[k++] = this->a[j++];
            }
        }
        while (i <= mid)
        {
            b[k++] = this->a[i++];
        }
        while (j <= high)
        {
            b[k++] = this->a[j++];
        }
        int l = 0;
        while (low <= high)
        {
            this->a[low++] = b[l++];
        }
        delete[] b;
        b = NULL;
    }

public:
    MergeSortIterative(int size)
    {
        this->size = size;
        this->length = 0;
        this->a = new T[this->size];
    }
    void set(T val)
    {
        this->a[this->length++] = val;
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
    void sort()
    {
        int i = 2;
        for (; i <= this->length; i *= 2)
        {
            for (int j = 0; j + i - 1 < this->length; j += i)
            {
                int l = j, h = j + i - 1;
                int mid = int((l + h) / 2);
                this->merge(l, mid, h);
            }
        }
        int mid = (i / 2);
        if (mid < this->length)
        {
            this->merge(0, mid - 1, this->length - 1);
        }
    }
};

int main()
{
    MergeSortIterative<int> ms(10);
    ms.set(7);
    ms.set(9);
    ms.set(4);
    ms.set(3);
    ms.set(2);
    ms.set(1);
    ms.set(8);
    ms.set(9);
    ms.set(7);
    ms.display();
    ms.sort();
    ms.display();

    MergeSortIterative<char> msc(10);
    msc.set('d');
    msc.set('a');
    msc.set('c');
    msc.set('h');
    msc.set('k');
    msc.set('z');
    msc.set('m');
    msc.set('l');
    msc.display();
    msc.sort();
    msc.display();
    return 0;
}