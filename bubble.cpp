#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
//#define MAX 2000;
using namespace std;


void swap(int arr[],int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr,j,j+1);
            }
        }
    }
}

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int a[] = {434,43,345,3453,54,3,545,35,3454,436,435,345,345,425,49,34};
    int size = sizeof(a)/sizeof(int);
    bubblesort(a,size);
    display(a,size);
    return 0;
}