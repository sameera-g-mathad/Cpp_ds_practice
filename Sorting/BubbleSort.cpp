#include <iostream>

using namespace std;

template <class T>
class BubbleSort
{
    T *array;
    int size;
    int length;
    int passes;
    void swap(int i, int j)
    {
        T temp = this->array[i];
        this->array[i] = this->array[j];
        this->array[j] = temp;
    }

public:
    BubbleSort(int size)
    {
        this->size = size;
        this->length = 0;
        this->passes = 0;
        this->array = new T[this->size];
    }
    void set(T val)
    {
        this->array[this->length++] = val;
    }
    int bubbleSort()
    {
        // n-1 passes for bubble sort. So run n-1 iterations
        for (int i = 0; i < this->length - 1; i++)
        {
            // This flag will test adaptiveness of bubble sort. If the array is already sorted it breaks the passes
            bool flag = false;
            // n-1 comparasions for bubble sort. n-i-1, because, in every ith iteration one element will be sorted.
            for (int j = 0; j < this->length - i - 1; j++)
            {
                // compare 2 elements
                if (this->array[j] > this->array[j + 1])
                {
                    this->swap(j, j + 1);
                    flag = true;
                }
            }
            this->passes++;
            if (!flag)
                break;
        }
        return this->passes;
    }
    void display()
    {
        cout << '\n';
        for (int i = 0; i < this->length; i++)
        {
            cout << this->array[i] << " ";
        }
        cout << '\n';
    }
};

int main()
{
    BubbleSort<int> sort_int(10);
    sort_int.set(9);
    sort_int.set(5);
    sort_int.set(3);
    sort_int.set(4);
    sort_int.set(2);
    sort_int.set(1);
    sort_int.set(7);
    sort_int.display();
    int passes = sort_int.bubbleSort();
    sort_int.display();
    cout << "Number of passes " << passes << endl;
    return 0;
}