#include<iostream>

using namespace std;

class Element{
    public:
    int row;
    int col;
    int value;
};

class Sparse{
    int m;
    int n;
    int num_of_non_zeroes;
    Element *element;
    public:
    Sparse(int m,int n,int num)
    {
        this->m = m;
        this->n = n;
        this->num_of_non_zeroes = num;
        element = new Element[this->num_of_non_zeroes];
    }
    ~Sparse()
    {
        delete []element;
    }
    void read()
    {
        cout<<"Enter non-zero element\n";
        for(int i=0;i<this->num_of_non_zeroes;i++)
        {
            cin>>element[i].row
            >>element[i].col
            >>element[i].value;
        }
    }
    void display()
    {
        // display as two dimensions
        int k=0;
        for(int i=0;i<this->m;i++)
        {
            for(int j=0;j<this->n;j++)
            {
                if(element[k].row==i && element[k].col==j)
                {
                    cout<<element[k++].value<<" ";
                }
                else{
                    cout<<0<<" ";
                }
            }
            cout<<endl;
        }
    }
};

int main()
{
    Sparse sp(5,5,5);
    sp.read();
    sp.display();
    return 0;
}