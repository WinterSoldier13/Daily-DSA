#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli unsigned long long int

int lowerBound(vector<int> &arr, int k)
{
    int l = arr.size();
    int start = 0;
    int end = l;
    int ans = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == k)
        {
            ans = mid;
            break;
        }
        else if (arr[mid] < k)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int upperBound(vector<int> &arr, int k)
{
    int start = 0;
    int end = arr.size();
    int ans = end - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == k)
        {
            ans = mid;
            break;
        }
        else if (arr[mid] > k)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
}