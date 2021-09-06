#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Insertion Sort

// Strart i from 1 to end
// temp = arr[i]
//  start j from i-1 to 0 and temp<arr[j]
//  Arr[j+1] = arr[j]
// after loop arr[j+1] = temp



void InsertionSort(vector<int> &arr)
{
    int l = arr.size();

    for(int i=1; i<l; i++)
    {
        int temp = arr[i];

        int j = i-1;
        while(j>=0 and temp<arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    for(int x: arr)
    cout<<x<<endl;
}

int main()
{
    vector<int> arr = {9,6,7,3,4,-1,4,2,1,3};
    InsertionSort(arr);
}
