#include<iostream>

using namespace std;

/*Diagonal Matrix is a matrix where diagonal of a matrix is non null and the rest of the elements is null.
Ex:
    3 0 0 0 0
    0 5 0 0 0
    0 0 6 0 0
    0 0 0 1 0
    0 0 0 0 9
 i.e, the elements are present when row and column number matches.
 -->  x if i==j 
 -->  0 else
 * Instead of storing the non-zero elements, we can store only the diagonal reducing space and time complexity from n2 to n.
*/
template<class T>
class DiagonalMatrix{
    private:
        int length; // length of single array storing diagonals. i.e the matrix is of length x length dimensions
        T *array; 
    public:
        DiagonalMatrix(int length)
        {
            this->length=length;
            this->array=new T[this->length];
        }
        ~DiagonalMatrix()
        {
            delete []array;
        }
        void set(int row,int column,T value)
        {
            // when row == column we set the value using either row or column as index
            // this->array[row-1] = value; For 1-index matrix 
            if(row == column)
            {
                this->array[row] = value;
            }
            else{
                cout<<"-------------"
                <<"Cannot add value at ("<<row<<", "<<column
                <<") as they don`t match"
                <<"-------------\n";
            }
        }
        T get(int row,int column)
        {
            if(row == column) return this->array[row];
            // if row != column, then return 0 as no value is stored in array
            return 0;
        }
        void display()
        {
            for(int i=0;i<this->length;i++)
            {
                for(int j=0;j<this->length;j++)
                {
                    if(i == j)  cout<<this->array[i]<<" ";
                    else cout<<0<<" ";
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
    // Since using templates we can use float,char(as far as i know😅)
    DiagonalMatrix<int> int_mat(length);
    // To display array before setting array.
    int_mat.display();
    // Set array. We can start from 1 as in matrix convention, we need to update set and get methods to reflect the same
    // We can take input from users as well.
    int_mat.set(0,0,5);
    int_mat.set(1,1,3);
    int_mat.set(2,2,6);
    int_mat.set(3,3,7);
    int_mat.set(4,4,9);
    cout<< int_mat.get(4,4)<<endl;
    int_mat.display();
    //when row!=column
    int_mat.set(2,3,5);
    return 0;
}