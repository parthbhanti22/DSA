#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#define MAX 2000
using namespace std;

int main()
{
    int n;
    int arr[] = {32,32,44,355,64,6643,255,25,2443,4};
    cout<<"Enter the index to be sliced\n";
    cin>>n;
    int subarr[MAX];
    for(int i=0;i<n;i++)
    {
        subarr[i] = arr[i];
        arr[i] = NULL;
    }
    cout<<"Both the subarrays are:\n";
    for(int i=0;)

}