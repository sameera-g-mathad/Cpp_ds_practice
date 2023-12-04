#include <iostream>

using namespace std;

class Array
{
private:
    int *a;
    int size;
    int length;

public:
    Array(int size, int length)
    {
        this->size = size;
        this->length = length;
        this->a = new int[size];
        cout << "enter array elements" << endl;
        for (int i = 0; i < this->length; i++)
        {
            cout << "enter element " << i + 1 << endl;
            cin >> this->a[i];
        }
    }
    int get_length()
    {
        return this->length;
    }
    void display()
    {
        cout << endl;
        for (int i = 0; i < this->size; i++)
        {
            cout << this->a[i] << " ";
        }
        cout << endl;
        // cout << this->length << endl;
    }
    void append(int value)
    {
        this->a[length++] = value;
        this->display();
    }
    void insert(int index, int value, char consent = 'n')
    {
        if (consent == 'y')
            this->recursive_insert(index, value, this->length);
        else
        {
            if (index == this->length)
                this->append(value);
            else if (index > this->length)
                cout << "Cannot add elements of invalid index";
            else
            {
                for (int i = this->length; i > index; i--)
                {
                    this->a[i] = this->a[i - 1];
                }
                this->a[index] = value;
                this->length++;
                this->display();
            }
        }
    }
    void recursive_insert(int index, int value, int length)
    {
        cout << endl;
        if (index == length)
        {
            this->a[index] = value;
            this->length++;
            this->display();
            return;
        }
        this->a[length] = this->a[length - 1];
        this->recursive_insert(index, value, length - 1);
    }
    void delete_element(int index, char consent = 'n')
    {
        if (consent == 'y')
        {
            cout << "element deleted " << this->recursive_delete(index, this->length);
            this->display();
        }
        else
        {
            cout << "element deleted " << this->a[index];
            for (int i = index; i < this->length; i++)
            {
                this->a[i] = this->a[i + 1];
            }
            this->length--;
            this->display();
        }
    }
    int recursive_delete(int index, int length)
    {
        if (index != length - 1)
        {
            int value = this->a[index];
            this->a[index] = recursive_delete(index + 1, length);
            return value;
        }
        this->length--;
        this->a[this->length] = 0;
        return this->a[index];
    }
    int recursive_linear_search(int key, int length)
    {
        if (length > 0)
        {
            recursive_linear_search(key, length - 1);
            if (key == this->a[length])
                return length;
        }
        return -1;
    }
    int linear_search(int key)
    {
        for (int i = 0; i < this->length; i++)
        {
            if (key == this->a[i])
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    cout << "----Array----" << endl;
    int size, length;

    cout << "enter size of the array" << endl;
    cin >> size;
    cout << "enter length of the array" << endl;
    cin >> length;
    Array arr(size, length);
    int choice;
    while (true)
    {
        cout << "enter operation\n1.append\n2.insert\n3.delete\n4.linear search\n5.display\n6.exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            arr.append(8);
            break;
        case 2:
            arr.insert(5, 6);
            break;
        case 3:
            arr.delete_element(5);
            break;
        case 4:
            int choice, key;
            cout << "enter key\n";
            cin >> key;
            cout << "enter choice\n1.Recursive\n2.Iterative\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << arr.recursive_linear_search(key, arr.get_length() - 1) << endl;
                break;
            case 2:
                cout << arr.linear_search(key) << endl;
                break;

            default:
                break;
            }
            break;
        case 5:
            arr.display();
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}