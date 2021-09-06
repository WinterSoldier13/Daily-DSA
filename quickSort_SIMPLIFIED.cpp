#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

int partition(vector<int> &arr, int start, int end)
{
    // select last element as the pivot
    int pivot = start + (end - start) / 2;

    int ptr1 = start;
    int ptr2 = end;

    while (ptr1 < ptr2)
    {
        while (arr[ptr1] < arr[pivot])
        {
            ptr1++;
        }

        while (arr[ptr2] > arr[pivot])
        {
            ptr2--;
        }

        if (ptr1 < ptr2)
        {
            int temp = arr[ptr1];
            arr[ptr1] = arr[ptr2];
            arr[ptr2] = temp;

            ptr1++;
            ptr2--;
        }
    }
    // swap(arr[ptr2], pivot);
    int temp = arr[ptr2];
    arr[ptr2] = arr[pivot];
    arr[pivot] = temp;

    return ptr2;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int part = partition(arr, start, end);
    quickSort(arr, start, part - 1);
    quickSort(arr, part + 1, end);
}

vector<int> doQuickSort(vector<int> arr)
{
    quickSort(arr, 0, (int)arr.size() - 1);
    return arr;
}

int main()
{
    vector<int> arr{5, 4, 3, 1, 2};

    arr = doQuickSort(arr);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}