#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void insertHeap(int *a, int child)
{
    while (child > 0)
    {
        int parent = int((child - 1) / 2);
        if (a[child] > a[parent])
        {
            swap(a[parent], a[child]);
        }
        child = int((child - 1) / 2);
    }
}
void deleteHeap(int *a, int n)
{
    swap(a[0], a[n]);
    int i = 0, j = 2 * (i + 1);
    while (j < n - 1)
    {
        if (a[j] < a[j - 1])
        {
            j = j - 1;
        }
        if (a[i] < a[j])
        {
            swap(a[i], a[j]);
            i = j;
            j = 2 * (i + 1);
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int a[] = {15, 70, 35, 63, 42, 51, 19, 2, 4};
    for (int i = 1; i < 9; i++)
    {
        insertHeap(a, i);
    }
    for (int i = 8; i > 1; i--)
    {
        deleteHeap(a, i);
        for (int i = 0; i < 9; i++)
        {
            cout << a[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}