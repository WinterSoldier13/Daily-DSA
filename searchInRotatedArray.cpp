#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

int getPivotpoint(vector<int> &arr)
{
    int l = arr.size();
    int start = 0;
    int end = l - 1;
    int ans = -1;
    if (is_sorted(arr.begin(), arr.end()))
    {
        return l - 1;
    }
    reverse(arr.begin(), arr.end());
    if (is_sorted(arr.begin(), arr.end()))
    {
        return 0;
    }
    reverse(arr.begin(), arr.end());

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid != 0 and mid != l - 1 and (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1]))
        {
            ans = mid;
            break;
        }
        else if (arr[mid] > arr[l - 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    if (ans == -1)
        ans = 0;
    return ans;
}

int binarySearch(vector<int> arr, int start, int end, int k)
{
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == k)
        {
            ans = mid;
            break;
        }
        else if (arr[mid] >= k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

void solve(vector<int> &arr, int k)
{
    int pivotPoint = getPivotpoint(arr);
    // cout << "Pivot " << pivotPoint << endl;

    int ans = -1;

    if (k >= arr[0] and k <= arr[pivotPoint])
    {
        ans = binarySearch(arr, 0, pivotPoint, k);
    }
    else
    {
        ans = binarySearch(arr, pivotPoint + 1, arr.size() - 1, k);
    }
    cout << ans << endl;
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        solve(arr, k);
    }

    return 1;
}