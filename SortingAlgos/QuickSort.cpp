#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (pivot >= a[start])
        {
            start++;
        }

        while (pivot < a[end])
        {
            end--;
        } 
        if (start < end)
        {
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[lb], &a[end]);
    return end;
}

void quickSort(int a[], int lb, int ub)
{
    int loc;
    if(lb<ub)
    {
        loc = partition(a, lb, ub);
        quickSort(a, lb, loc - 1);
        quickSort(a, loc + 1, ub);
    }
}

int main()
{

    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    cout << "Before Sorting :\n";
    for (i = 0; i < 10; i++)
        cout << A[i] << "  ";
    cout << "\n";
    cout << "After Sorting :\n";
    quickSort(A, 0, n);
    for (i = 0; i < 10; i++)
        cout << A[i] << "  ";
    cout << "\n";
    return 0;
}