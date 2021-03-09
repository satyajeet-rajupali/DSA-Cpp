#include<iostream>
using namespace std;

class Queue{
private:
    int Rear;
    int Front;
    int arr[5];

public:
    Queue()
    {
        Front = -1;
        Rear = -1;
        for(int i=0; i<5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if(Front == -1 && Rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if(Rear == 4)
            return true;
        else
            return false;
    }


    void Enqueue(int val)
    {
        if(isFull())
        {
            cout<<"Queue is Full"<<endl;
            return;
        }
        else if(isEmpty())
        {
            Rear = 0;
            Front = 0;
            arr[Rear] = val;
        }
        else
        {
            Rear++;
            arr[Rear] = val;
        }
    }

    int Dequeue()
    {
        int x =0;
        if(isEmpty())
        {
            cout<<"Queue is Empty\n";
            return 0;
        }
        else if(Rear == Front)
        {
            x = arr[Front];
            arr[Front] = 0;
            Rear = -1;
            Front = -1;
            return x;

        }
        else
        {
            x = arr[Front];
            arr[Front] = 0;
            Front++;
            return x;
        }
    }

    int Count()
    {
        if((Rear - Front) == 0)
            return 0;
        else
            return ((Rear - Front)+1);
    }

    void display()
    {
        cout<<"All the value in the queue are: "<<endl;
        for(int i = 0; i<5; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

int main(){

    Queue q1;
    int option;
    int value;
    do
    {
        cout<<"\nWhat operation do you want to perform? Select option number. Enter 0 to exit.\n"
        <<"1. Enqueue()\n"
        <<"2. Dequeue()\n"
        <<"3. isEmpty()\n"
        <<"4. isFull()\n"
        <<"5. count()\n"
        <<"6. display()\n"
        <<"7. Clear Screen\n\n";

        cin>>option;

        switch(option)
        {
        case 0:
            break;

        case 1:
            cout<<"Enqueue operation \n Enter an item to Enqueue in the Queue"<<endl;
            cin>>value;
            q1.Enqueue(value);
            break;

        case 2:
            cout<<"Dequeue Operation \nDequeue Value: "<<q1.Dequeue()<<endl;
            break;

        case 3:
            if(q1.isEmpty())
                cout<<"Queue is Empty"<<endl;
            else
                cout<<"Queue is not Empty"<<endl;
            break;

        case 4:
            if(q1.isFull())
                cout<<"Queue is Full"<<endl;
            else
                cout<<"Queue is not Full"<<endl;
            break;

        case 5:
            cout<<"Count Operation \nCount of items in Queue: "<<q1.Count()<<endl;
            break;

        case 6:
            cout<<"Display Function called - "<<endl;
            q1.display();
            break;

        case 7:
            system("cls");
            break;

        default:
            cout<<"Invalid Case\n";

        }

    }while(option!=0);

    return 0;

}
