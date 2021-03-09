#include<iostream>
using namespace std;

class Array
{
    private:
        int *a;
        int length;
    public:
        Array()
        {
            length = 0;
            a = new int;
        }

        ~Array()
        {
            delete []a;
        }

        void operator =(Array &A3 ) 
        {
            length = A3.length;
            for(int i =0; i<A3.length; i++)
            {
                 a[i] = A3.a[i];
            }
        }

        void Display();
        void Append(int);
        void Insert(int, int);
        int Size();
        int Delete(int);
        int LinearSearch(int);
       
};


int Array::LinearSearch(int element)
{
    for(int i=0; i<length; i++)
    {
        if(a[i] == element)
            return i;
    }
    return -1;
}

void Array::Display()
{
    cout<<"Elements in the Array\n";
    for(int i=0; i<length; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void Array::Append(int element)
{
    
    a[length++] = element;
    cout<<"Element Addded\n";
}

void Array::Insert(int element, int index)
{
    if(index>=0 && index<=length )
    {
        for(int i=length; i>index;i--)
            a[i] = a[i-1];
        a[index] = element;
        length++;
        cout<<"***Element Inserted Successfully***\n";
    }
    else
    {
        cout<<"\n**Overflow**\n";
    }
    
}

int Array::Size()
{
    return length;
}

int Array::Delete(int element)
{
    int index = LinearSearch(element);
    if( index == -1)
        cout<<"Can't delete element as it isn't present in the array\n";
    else
    {
        int x = a[index];
        for(int i=index; i<(length-1); i++)
            a[i] = a[i+1];
        length--;
        return index;
    }
    return 0;
}



int main()
{
    Array A, A1, A2;
    int ch, element, pos;

    do
    {
        cout<<"\nMenu:\n"
        <<"1.Append"<<"\t"<<"2.Insert"<<"\t"<<"3.Delete"<<"\n"
        <<"4.Size"<<"\t"<<"5.Display()"<<"\t"<<"0.Exit<<"<<endl;

        cout<<"Enter Your Choice\n";
        cin>>ch;

        switch (ch)
        {

        case 0:
            break;
        
        case 1:
            cout<<"\nEnter the element to append/add into array\n";
            cin>>element;
            A.Append(element);
            break;

        case 2:
            cout<<"\nEnter the element and it's position to insert\n";
            cin>>element>>pos;
            A.Insert(element, pos);
            break;

        case 3:
            cout<<"\nEnter the Element to delete\n";
            cin>>element;
            cout<<"*****"<<element<<" at "<< A.Delete(element)<<" is Deleted Successfully******\n";
            break;
        
        case 4:
            cout<<"\nSize of the array is "<<A.Size()<<endl;
            break;

        case 5:
            A.Display();
            break;

        }
    } while (ch!=0);

    cout<<"\n\n\t*****Program has Ended Now*****\t\n\n";
    
    return 0;
}

