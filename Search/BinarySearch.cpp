      // Sample program to demonstrate the working of the Binary Search operation on Arrays
#include<iostream>
using namespace std;

int main()
{
    int a[5] = {101,202,303,404,505};
    int Mid;
    int Beg = 0;
    int End = 4;
    int item;
    int index;

    cout<<"Elements Present in array\n";
    for(int i=0; i<5; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";

    Mid = (Beg + End)/2;
    cout<<"Enter the number to perform Binary Search\n";
    cin>>item;
    while((Beg<=End)&&(a[Mid]!=item))
    {
        if(item<a[Mid]){
            End = Mid - 1;
        }
        else
        {
            Beg = Mid + 1;
        }

        Mid = (Beg + End)/2;
    }

    if(Beg>End)
    {
        index = -1;
    }
    else
    {
        index = Mid;
    }

    if(index == -1)
    {
        cout<<"*************Element not Found!!*************\n";
    }
    else
    {
        cout<<item<<" is found at "<<index + 1<<" position."<<"\n";
    }
    return 0;
}
