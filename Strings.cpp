#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

class Strings{
    private:
        int size,length;
        char  *str;
    public:
        Strings(char  *str,int size=0)
        {
            int i;
            this->size = size;
            this->str = new char[size];
            for( i=0;str[i]!='\0';i++)
            {   
                this->str[i]=str[i];
            }
            this->str[i]='\0';
        }
        void display()
        {
            cout<<str<<endl;
        }
        int str_length()
        {
            int i,len=0;
            for(i=0;this->str[i]!='\0';i++)
            {
                len++;
            }
            this->length=len;
            return len;
        }
        int str_length(char *str)
        {
            int i,len=0;
            for(i=0;str[i]!='\0';i++)
            {
                len++;
            }
            return len;
        }
        int str_length_recursive(int index)
        {
            if(this->str[index]=='\0')
                return index;
            return str_length_recursive(index+1);
        }
        void lower_case()
        {
            for(int i=0;this->str[i]!='\0';i++)
            {
                if(this->str[i]<=90 && this->str[i]>=65)
                {
                    this->str[i]+=32;
                }
            }
        }
        void upper_case()
        {
            for(int i=0;this->str[i]!='\0';i++)
            {
                if(this->str[i]<=122 && this->str[i]>=97)
                {
                    this->str[i]-=32;
                }
            }
        }
        bool is_lower_case()
        {
            for(int i=0;this->str[i]!='\0';i++)
            {
                if(this->str[i]>=65 && this->str[i]<=90)
                    return false;
            }
            return true;
        }
        void toggle_case()
        {
            if(is_lower_case())
            {
                this->upper_case();
            }
            else
            {
                this->lower_case();
            }
        }
        char *substring(int start,int end)
        {
            char *new_str;
            int i,j;
            for( i=start,j=0;i<=end;i++,j++)
            {
                if(str[i]=='\0')break;
                new_str[j]=this->str[i];
            }
            new_str[j]='\0';
            return new_str;
        }
        char *substring(char *sstr,int start,int end)
        {
            char *new_str;
            int i,j;
            for(i=start,j=0;i<=end;i++,j++)
            {   
                if(sstr[i]=='\0')break;
                new_str[j]=sstr[i];
            }
            new_str[j]='\0';
            return new_str;
        }
        char *trim_str(char *tstr)
        {
            int i=0;
            int j=this->str_length(tstr);
            while(tstr[i]==' ')
                i++;
            while(tstr[j]==' ')
                j--;
            
            char *new_str= this->substring(tstr,i,j);
            return new_str;
        }
        bool validate(char *str)
        {
            for(int i=0;i<this->str_length(str);i++)
            {
                // alpha-numeric [if character is not small case] Or [if character is not a capital case] Or [if character is not a digit]
                // return false
                if(!(str[i]>=97 && str[i]<=122) && !(str[i]>=65 && str[i]<=90) && !(str[i]>=48 && str[i]<=57))
                    return false;
            }
            return true;
        }
        void print_str_reverse(char *str,int index)
        {
            if(str[index]=='\0') return;
            print_str_reverse(str,index+1);
            cout<<str[index];
            return;
        }
        void swap(char *a,char *b)
        {
            int temp=*a;
            *a=*b;
            *b=temp;
        }
        void reverse_str(char *str)
        {
            int length=this->str_length(str);
           
            for(int i=0,j=length-1;i<j;i++,j--)
            {
                swap(&str[i],&str[j]);
            }
            
        }
};


int main()
{
    cout<<"Welcome to strings practice\n\n.Enter String and size of string array\n";
    int size;
    cout<<"Enter size\n";
    cin>>size;
    char str[]= "sAMEER GuruRAJ MatHAd";
    Strings strs(str,size);
    int choice;
    bool loop=true;
    while(loop)
    {
        cout<<"\nEnter choice\n1.Display String.\n2.Length of string.\n3.Lower case of string.\n4.Upper case of string.\n5.Toggle case of string.\n6.Substring.\n7.Trim.\n8.Validate String\n9.Print a String in reverse\n10.Reverse a string\n";
        cin>>choice;
        switch(choice)
        {
            case 1: strs.display();
                    break;
            case 2: cout<<strs.str_length();
                    break;
            case 3: strs.lower_case();
                    break;
            case 4: strs.upper_case();
                    break;
            case 5: strs.toggle_case();
                    break;
            case 6: {
                char *s;
                cout<<"Enter string for substring😂\n";
                cin>>s;
                char *new_str=strs.substring(s,1,8);
                cout<<new_str<<endl;   
            }
            break;
            case 7:{
                char *str="   sameer23431      ";
                char *new_str=strs.trim_str(str);
                cout<<new_str<<endl;
                break;
            }
            case 8:{
                char *str = new char[20];
                cout<<"Enter string to check validation\n";
                scanf("%s",str);
                cout<<((strs.validate(str)) ==1? ("String is valid"):("String is not valid"))<<endl;
                break;
            }
            case 9:{
                char *str = new char[20];
                cout<<"enter string to print reverse\n";
                cin>>str;
                strs.print_str_reverse(str,0);
                break;
            }
            case 10:{
                char *str=new char[20];
                cout<<"enter string to reverse\n";
                cin>>str;
                strs.reverse_str(str);
                cout<<"The reversed string is"<<str;
                break;
            }
            default: loop=false;
                    break;
        }
    }
}