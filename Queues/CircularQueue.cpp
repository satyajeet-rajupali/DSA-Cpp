#include<iostream>
using namespace std;


class CircularQueue
{
    private:
        int *arr;
        int rear;
        int front;
        int size;

    public:
        CircularQueue()
        {
            rear = front = -1;
            arr = new int;
        }
        CircularQueue(int size)
        {
            rear = front = -1;
            this->size  = size;
            arr = new int[size];
            for(int i=0; i<size; i++)
                arr[i] = 0;
        }

        bool isFull();
        bool isEmpty();
        void enqueue(int);
        int dequeue();
        int count();
        void display();

};


// To check whether CircularQueue is empty or not.

bool CircularQueue::isEmpty()
{
    if(rear == -1 && front == -1)
        return true;
    else
        return false;
}


// To check whether CircularQueue is full or not.

bool CircularQueue::isFull()
{
    if(((rear+1)%size) == front)
        return true;
    else
        return false;
}


// To add an element inside the CircularQueue.
void CircularQueue::enqueue(int element)
{
    if(isFull())
        cout<<"*****Queue is Full*****\n";
    else if (isEmpty())
        rear = front = 0;
    else
        rear = (rear+1)%size;
    arr[rear] = element;
}


// To remove an element from the CicularQueue.
int CircularQueue::dequeue()
{
    int dequedValue;
    if(isEmpty())
    {
        cout<<"*****Queue is empty*****\n";
        return 0;
    }
    else if(rear == front)
    {
        dequedValue = arr[front];
        arr[front] = 0;
        rear = front = -1;
    }
    else
    {
        dequedValue = arr[front];
        arr[front] = 0;
        front++;
    }
    return dequedValue;
}


// To get the size of the CircularQueue.
int CircularQueue::count()
{
    return (rear - front) + 1;
}


// To display the elements of the CircularQueue.

void CircularQueue::display()
{
    cout<<"Elements inside the queue\n";
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main()
{
    CircularQueue CQ(5);
    int element;
    int option;

    do
    {
        cout<<"Menu - Enter the operation code to perform the operation: \n"
        <<"1.enqueue()"<<"\t"<<"2.dequeue"<<"\t"<<"3.isEmpty()"<<"\t"<<"4.isFull()"<<"\n"
        <<"5.count()"<<"\t"<<"6.display()"<<"\t"<<"7.Exit()"<<endl;

        cin>>option;

        switch (option)
        {
        case 1:
            cout<<"Enter the value to add into the queue:\n";
            cin>>element;
            CQ.enqueue(element);
            break;

        case 2:
            cout<<"Value dequed is "<<CQ.dequeue()<<endl;
            break;

        case 3:
            if(CQ.isEmpty())
                cout<<"*****Queue is Empty*****\n";
            else
                cout<<"*****Queue has somevalue*****\n";
            break;

        case 4:
            if(CQ.isFull())
                cout<<"*****Queue is Full*****\n";
            else
                cout<<"*****Queue has some vacant space*****\n";
            break;

        case 5:
            cout<<"Size of queue is "<<CQ.count()<<endl;
            break;

        case 6:
            CQ.display();
            break;
    
        default:
            break;
        }

    } while (option<7);

    cout<<"\n\n\t*******Program Ended********\t\n\n";
    return 0;
}