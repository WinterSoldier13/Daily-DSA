#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// SELECTION SORT
// Start from index 0
// Find the index of min_ele
// Swap arr[min_index] and arr[0]
// move the pointer to 1
// Find the index of min_ele in the remaing array... i.e starting from index 1 and till end
// swap arr[1] with arr[min_index]
// continue


void selectionSort(vector<int> &arr)
{
    int l = arr.size();

    for(int i=0;i<l;i++)
    {
        int eleI = arr[i];
        int min_index = i;
        int min_element = arr[i];
        for(int j = i;j<l;j++)
        {
            int eleJ = arr[j];
            if(min_element<eleJ)
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }

    for(int x: arr)
    cout<<x<<endl;
}

int main()
{
    vector<int> arr = {9,6,7,3,4,-1,4,2,1,3};
    selectionSort(arr);
}
