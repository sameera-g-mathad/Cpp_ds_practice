#include<iostream>

using namespace std;

class Set{
     public:
    int *array;
    int length;
    Set(int a_length,int b_length){
        int total_length = a_length + b_length;
        this->array = new int[total_length];
        this->length = total_length;
    }
    Set(int *array,int length)
    {
        this->array = array;
        this->length = length;
    }
    void display()
    {
        for(int i=0;i<this->length;i++)
        {
            cout<<this->array[i]<<'\t';
        }
        cout<<'\n';
    }
    void set_union(Set a,Set b)
    {
        int i=0,j=0,k=0;
        int count = 0;
        while(i<a.length && j<b.length)
        {
            count++;
            if(a.array[i] < b.array[j])
            {
                this->array[k++] = a.array[i++];
            }
            else if(a.array[i] > b.array[j])
            {
                this->array[k++] = b.array[j++];
            }
            else{
                this->array[k++] = a.array[i++];
                j++;
            }
        }
        while(i<a.length)
        {
            count++;
            this->array[k++] = a.array[i++];
        }
        while(j<b.length)
        {
            count++;
            this->array[k++] = b.array[j++];
        }
        cout<<count<<endl;
    }
    void set_intersection(Set a,Set b)
    {
        int i=0,j=0,k=0;
        while(i<a.length && j<b.length)
        {
            if(a.array[i] < b.array[j])
                i++;
            else if(a.array[i] > b.array[j])
                j++;
            else{
                this->array[k++] = a.array[i++];
                j++;
            }
        }
        while(k<this->length)
        {
            this->array[k++] = 0;
        }
    }
    void set_difference(Set a,Set b)
    {
        int i=0,j=0,k=0;
        while(i<a.length && j<b.length)
        {
            if(a.array[i] < b.array[j])
            {
                this->array[k++] = a.array[i++];
            }
            else if(a.array[i] > b.array[j])
                j++;
            else{
                i++;
                j++;
            }
        }
        while(i<a.length)
        {
            this->array[k++] = a.array[i++];
        }
        while(k<this->length)
        {
            this->array[k++] = 0;
        }
    }
};

int main()
{
    int a[]={1,2,3,4,5,9,11,12};
    int b[]={2,3,5,6,7,8,9,10};
    int a_length = (sizeof(a)/sizeof(a[0]));
    int b_length = (sizeof(b)/sizeof(b[0]));
    Set set_a(a,a_length);
    Set set_b(b,b_length);
    Set set_c(a_length,b_length);
    set_c.set_union(set_a,set_b);
    cout<<"Union\n";
    set_c.display();
    set_c.set_intersection(set_a,set_b);
    cout<<"Intersection\n";
    set_c.display();
    set_c.set_difference(set_a,set_b);
    cout<<"A-B\n";
    set_c.display();
    set_c.set_difference(set_b,set_a);
    cout<<"B-A\n";
    set_c.display();
    return 0;
}