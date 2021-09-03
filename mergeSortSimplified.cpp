#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

void mergeTwoSortedArray(vector<int> &arr, vector<int> &temp, int start, int mid, int end)
{
    // okay so here my first array is start to mid
    // my second array is mid+1 to end

    int leftStart = start;
    int leftEnd = mid;

    int rightStart = mid + 1;
    int rightEnd = end;

    int tempArrIndex = leftStart;

    while (leftStart <= leftEnd and rightStart <= rightEnd)
    {
        if (arr[leftStart] <= arr[rightStart])
        {
            temp[tempArrIndex] = arr[leftStart];
            leftStart++;
        }
        else
        {
            temp[tempArrIndex] = arr[rightStart];
            rightStart++;
        }
        tempArrIndex++;
    }

    // add the remaining elements to the temp array
    while (leftStart <= leftEnd)
    {
        temp[tempArrIndex] = arr[leftStart];
        tempArrIndex++;
        leftStart++;
    }
    while (rightStart <= rightEnd)
    {
        temp[tempArrIndex] = arr[rightStart];
        tempArrIndex++;
        rightStart++;
    }

    // copy the sorted content back to the main array
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(vector<int> &arr, vector<int> &temp, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;

    mergeSort(arr, temp, start, mid);
    mergeSort(arr, temp, mid + 1, end);
    mergeTwoSortedArray(arr, temp, start, mid, end);
}

vector<int> mergeSortArr(vector<int> arr)
{
    int n = arr.size();
    vector<int> temp(n);

    mergeSort(arr, temp, 0, n - 1);

    return arr;
}

int main()
{
    vector<int> arr{5, 4, 3, 2, 1};

    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    arr = mergeSortArr(arr);

    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}