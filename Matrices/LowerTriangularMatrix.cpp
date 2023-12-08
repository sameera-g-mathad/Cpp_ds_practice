#include<iostream>

using namespace std;

/*Lower Triangular Matrix is a matrix where diagonal and the bottom part of diagonal of a matrix is non null, rest of the elements is null.
Ex:
    3 0 0 0 0
    3 5 0 0 0
    2 4 6 0 0
    7 7 8 1 0
    8 4 2 5 9
 i.e, the elements are present when row and column number matches.
 -->  x if i==j 
 -->  x if i>j
 -->  0 else
 * Instead of storing the non-zero elements, we can store only the non-null reducing space and time complexity from n2 to n(n+1)/2.
Ex: if n=5, n2=25, n(n+1)/2=15. There will be n(n-1)/2 zero elements.
*/
template<class S>
class LowerTriangularMatrix
{
    private:
    int length;
    int dimension;
    S *array;
    public:
    LowerTriangularMatrix(int length)
    {
        // as we only need n(n+1)/2 space to store elements.
        this->length = (length*(length+1)/2);
        this->dimension=length;
        this->array = new S[this->length];
    }
    ~LowerTriangularMatrix()
    {
        delete []array;
    }
    int getlength()
    {
        return this->length;
    }
    int calculateIndex(int row,int column)
    {
       int index = (row*(row+1))/2 + column;
       return index;
    }
    void set(int row,int column,S value)
    {
        if(row>=column)
        {
            // row-mapping
            int index = calculateIndex(row,column);
            this->array[index] = value;
        }
        else{
            
                cout<<"-------------"
                <<"Cannot add value at ("<<row<<", "<<column
                <<") as they column value is greater"
                <<"-------------\n";
            
        }
    }
    S get(int row,int column)
    {
        if(row>=column)
        {
            // row-mapping
            int index = calculateIndex(row,column);
            return this->array[index];
        }
        return 0;
    }
    void display()
    {
        for(int j=0;j<this->length;j++)
        {
            cout<< this->array[j]<<" ";
        }
        cout<<'\n';
        for(int i=0;i<this->dimension;i++)
        {
            for(int j=0;j<this->dimension;j++)
            {
                if(i>=j)
                {
                    int index = calculateIndex(i,j);
                    cout<<this->array[index];
                }
                else{
                    cout<<0;
                }
                cout<<" ";
            }
            cout<<'\n';
        }
    }
};

int main()
{
    cout<< "Enter length of the matrix"<<endl;
    int length;
    cin>>length;
    LowerTriangularMatrix<int> int_ltm(length);
    cout<<"Length of array needed "<<int_ltm.getlength()<<endl;
    cout<<"Enter row, column, value"<<endl;
    for(int i=0;i<int_ltm.getlength();i++)
    {
        int row,column,value;
        cin>>row>>column>>value;
        int_ltm.set(row,column,value);
    }
    int_ltm.display();
    return 0;
}