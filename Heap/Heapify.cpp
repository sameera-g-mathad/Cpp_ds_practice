#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void heapify(int *a, int length)
{
    int i = int((length - 1) / 2);
    while (i >= 0)
    {
        int j = 2 * i + 1;
        if ((j + 1) <= length)
        {
            if (a[j] < a[j + 1])
            {
                j = j + 1;
            }
        }
        if (a[i] < a[j])
        {
            swap(a[i], a[j]);
            i = j + 1;
        }
        i--;
    }
}
void deleteHeap(int *a, int length)
{
    swap(a[0], a[length]);
    int i = 0;
    int j = 2 * i + 1;
    while (j < length - 1)
    {
        if (a[j] < a[j + 1])
        {
            j = j + 1;
        }
        if (a[i] < a[j])
        {
            swap(a[i], a[j]);
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
}
void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';
}
int main()
{
    int n;
    cout << "Enter the number of elements in the array\n";
    cin >> n;
    int a[n];
    cout << "Enter the number of elements in the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    heapify(a, n - 1);
    display(a, n);
    for (int i = n - 1; i > 1; i--)
    {
        deleteHeap(a, i);
    }
    display(a, n);
    return 0;
}