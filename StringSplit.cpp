/*
----------------------NOte-----------------
Still need to look once again and make it workable using OOP.
*/

// I believe this works in o(n).
#include <iostream>

using namespace std;

char ** string_split(char *str,char delimiter,int length)
{
    int i=0,j=0,setChar=0,k=0;
    char *substring;
    char **result = new char*[5];
    for(int i=0;str[i]!='\0';i++)
    {
        if(setChar == 0)
        {
        substring = new char[length];
        setChar =1;
        }
        if(str[i] == delimiter)
        {
            substring[k]='\0';
            result[j]=substring;
            // I thought i needed to delete this, but since result is pointing to substring, no need to delete it.
            //delete substring;
            setChar=0;
            k=0;
            j++;
        }
        else
        substring[k++]=str[i];
    
    }
    result[j]=substring;
    return result;
}
int main()
{
    char s[] = "Hello,World,sameer,ok";
    int length = sizeof(s)/sizeof(s[0]);
    char **result = string_split(s,',',length);
    cout<<'[';
    for(int i=0;i<3;i++)
    {
        cout<<result[i]<<", ";
    }
    cout<<result[3];
    cout<<']';
    return 0;
}