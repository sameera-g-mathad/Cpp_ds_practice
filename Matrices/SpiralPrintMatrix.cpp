// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Matrix
{
    int a[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    int m = 5;
    int n = 5;

public:
    Matrix()
    {
        for (int i = 0; i < this->m; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                cout << a[i][j] << "\t";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    void printRow(int m, int n, int i, int j, bool flag)
    {
        if (this->n == 0)
            return;
        if (flag)
        {
            while (j >= (n - this->n))
            {
                cout << this->a[i][j] << " ";
                j--;
            }
            this->m--;
            this->printColumn(m - 1, n, i - 1, j + 1, true);
        }
        else
        {
            while (j < n)
            {
                cout << this->a[i][j] << " ";
                j++;
            }
            j--;
            this->m--;
            this->printColumn(m, n, i + 1, j, false);
        }
    }
    void printColumn(int m, int n, int i, int j, bool flag)
    {
        if (this->m == 0)
            return;
        if (flag)
        {
            while (i >= (m - this->m))
            {
                cout << this->a[i][j] << " ";
                i--;
            }
            this->n--;
            this->printRow(m, n, i + 1, j + 1, false);
        }
        else
        {
            while (i < m)
            {
                cout << this->a[i][j] << " ";
                i++;
            }
            i--;
            this->n--;
            this->printRow(m, n - 1, i, j - 1, true);
        }
    }
};

int main()
{
    Matrix m;
    m.printRow(5, 5, 0, 0, false);
    return 0;
}