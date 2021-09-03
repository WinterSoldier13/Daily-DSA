#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int pivotElement(vector<int> &arr)
{
    int l = arr.size();
    int start = 0;
    int end = l;
    int ans = 0;

    //check for decreasing order
    if (arr[0] > arr[1] and arr[l - 2] > arr[l - 1])
    {
        ans = -1;
    }
    else
    {
        if (arr[0] > arr[l - 1])
        {

            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                if (arr[mid] > arr[mid + 1])
                {
                    ans = mid + 1;
                    break;
                }
                if (arr[start] <= arr[mid])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
    }

    return ans;
}

int search(vector<int> &arr, int target)
{
    if (arr.size() == 0)
    {
        return -1;
    }
    if (arr.size() == 1 and target == arr[0])
    {
        return 0;
    }
    else if (arr.size() == 1)
    {
        return -1;
    }
    int pivot = pivotElement(arr);
    int start = 0;
    int end = arr.size() - 1;

    if (!(pivot == 0))
    {
        if (arr[pivot] == target)
        {
            return pivot;
        }
        if (target > arr[0])
        {
            end = pivot - 1;
        }
        else
        {
            start = pivot + 1;
        }
    }

    if (pivot == -1)
    {
        start = arr.size() - 1;
        end = 0;

        while (end <= start)
        {
            int mid = end + (start - end) / 2;

            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] < target)
            {
                start = mid - 1;
            }
            else
            {
                end = mid + 1;
            }
        }
        return -1;
    }

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr{3, 1};

    cout << search(arr, 0) << endl;

    return 0;
}