#include<iostream>

using namespace std;

class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        for(int i=0; i<5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if(top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if(top == 4)
            return true;
        else
            return false;
    }

    void push(int val)
    {
        if(isFull())
        {
            cout<<"Stack Overflow\n";
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow\n";
            return 0;
        }
        else
        {
            int popVal = arr[top];
            arr[top] = 0;
            top--;
            return popVal;
        }
    }

    int Count()
    {
        return (top+1);
    }

    int peek(int pos)
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow\n";
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }

    void change(int pos, int val)
    {
        arr[pos] = val;
        cout<<"Value changed at the location  "<<pos<<endl;
    }

    void display()
    {
        cout<<"All values in the stack are "<<endl;
        for(int i=4; i>=0; i--)
        {
            cout<<arr[i]<<endl;
        }
    }
};


int main()
{
    Stack S1;
    int option,value,pos;
    do
    {
        cout<<"What option do you want to perform. Select the option number. Enter 0 to exit.\n"
        <<"1. push()\n"
        <<"2. pop()\n"
        <<"3. isEmpty()\n"
        <<"4. isFull()\n"
        <<"5. peek()\n"
        <<"6. Count()\n"
        <<"7. change()\n"
        <<"8. display()\n"
        <<"9. clear screen\n";

        cin>>option;
        switch(option)
        {
        case 0:
            break;

        case 1:
            cout<<"Enter the item to push into the stack\n";
            cin>>value;
            S1.push(value);
            break;

        case 2:
            cout<<"Pop Function Called- Popped Value: "<<S1.pop()<<endl;
            break;

        case 3:
            if(S1.isEmpty())
                cout<<"Stack is Empty"<<endl;
            else
                cout<<"Stack is not Empty"<<endl;
            break;

        case 4:
            if(S1.isFull())
                cout<<"Stack is full"<<endl;
            else
                cout<<"Stack is not full"<<endl;
            break;

        case 5:
            cout<<"Enter the position of the item you want to peek: "<<endl;
            cin>>pos;
            cout<<"Peek Function Called- Value at is "<<pos<<" position "<<S1.peek(pos)<<endl;
            break;

        case 6:
            cout<<"Count function called- Number of items in the stack are: "<<S1.Count()<<endl;
            break;

        case 7:
            cout<<"Change function called- "<<endl;
            cout<<"Enter the position of the item you want to change"<<endl;
            cin>>pos;
            cout<<"Enter the value of the item you want to change"<<endl;
            cin>>value;
            S1.change(pos,value);
            break;

        case 8:
            cout<<"Display function called- "<<endl;
            S1.display();
            break;

        case 9:
            system("cls");
            break;

        default:
            cout<<"Enter the proper option number"<<endl;
        }
    }while(option!=0);
}
