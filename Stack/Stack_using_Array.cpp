#include<iostream>

using namespace std;

template<typename S>
class Stack_Array
{
    int size;
    int top;
    S *array;
    public:
    Stack_Array(int size)
    {
        this->size = size;
        this->top = -1;
        this->array = new S[this->size];
    }

    bool isStackEmpty()
    {
        return this->top == -1;
    }

    bool isStackFull()
    {
        return this->top == (this->size - 1) ;
    }
    void push(S data)
    {
        if(!isStackFull())
        {
            array[++top] = data;
        }
    }
    S pop()
    {
        if(!isStackEmpty())
        {
            return array[top--];
        }
        return -1;
    }
    /*
      0 1 2 3 4  -- regular index
     [4 3 2 9 8] -- data
      4 3 2 1 0  -- indexing from top

      Ex: To get element in index 1 == we can acess by top - 1 ==> 4-1 == 3
    */
    S peek(int index)
    {
        if(index >0 && index < size)
        {
            return array[top - index];
        }
        return -1;
    }
    void display()
    {
        if(!isStackEmpty())
        {
            int i=0;
            for(int i=top;i>=0;i--)
            {
                cout<< array[i];
            }
        }
    }
};
int main()
{
    Stack_Array<int> st(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(9);
    st.push(8);
    cout<< "Popped data is "<< st.pop()<<endl;
    cout<< "Data is "<<st.peek(2)<<endl;
    cout<< "Data is "<<st.peek(29)<<endl;
    st.push(7);
    st.display();
    return 0;
}