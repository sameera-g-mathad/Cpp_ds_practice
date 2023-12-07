#include<iostream>

using namespace std;

template<class T>
class DiagonalMatrix{
    int length;
    T *a;
    public:
    DiagonalMatrix(int length)
    {
        this->length = length;
        this->a = new T[this->length];
    }
    void set(int i,int j,T x)
    {
        if(i == j)
        {
            this->a[i]=x;
        }
    }
    T get(int i,int j)
    {
        if(i==j)
        {
            return this->a[i];
        }
        return 0;
    }
    void display()
    {
        for(int i=0;i<this->length;i++)
        {
            for(int j=0;j<this->length;j++)
            {
                if(i == j)
                {
                    cout<<this->a[i]<<'\t';
                }
                else{
                    cout<<0<<'\t';
                } 
            }
            cout<<'\n';
        }
    }
    ~DiagonalMatrix()
    {
        delete []a;
    }
};

int main()
{
    DiagonalMatrix<int> mat(5);
    mat.set(0,0,4);
    mat.set(2,2,3);
    mat.set(1,1,7);
    mat.set(3,3,2);
    mat.set(4,2,7);
    mat.set(4,4,9);
    mat.display();

    DiagonalMatrix<float> mat_float(5);
    mat_float.set(0,0,4.5);
    mat_float.set(2,2,3.6);
    mat_float.set(1,1,7.7);
    mat_float.set(3,3,2.7);
    mat_float.set(4,2,7.8);
    mat_float.set(4,4,9.4);
    mat_float.display();
    cout<<mat_float.get(2,3)<<endl;
    
    DiagonalMatrix<char> mat_char(5);
    mat_char.set(0,0,'a');
    mat_char.set(2,2,'b');
    mat_char.set(1,1,'c');
    mat_char.set(3,3,'d');
    mat_char.set(4,2,'f');
    mat_char.set(4,4,'e');
    mat_char.display();
    cout<<mat_char.get(2,2)<<endl;
}