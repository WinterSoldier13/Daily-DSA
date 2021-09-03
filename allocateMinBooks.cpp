#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

int getSum(int *arr, int n)
{
    int sum_ = 0;
    for (int i = 0; i < n; i++)
    {
        sum_ += arr[i];
    }
    return sum_;
}

bool isValid(int *arr, int n, int m, int k)
{
    int count = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > k)
        {
            return 0;
        }
        if (sum + arr[i] <= k)
            sum += arr[i];
        else
        {
            sum = arr[i];
            count++;
        }
        if (count > m)
        {
            return 0;
        }
    }
    return 1;
}

int findPages(int *arr, int n, int m)
{
    if (n < m)
    {
        return -1;
    }

    int min_ = arr[0];
    int max_ = getSum(arr, n);

    int start = 0;
    int end = max_;
    int ans = INT_MAX;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isValid(arr, n, m, mid))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    if (ans == INT_MAX)
        return -1;
    return ans;
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[5] = {51, 151, 227, 163, 55};
    int n = 5;
    int m = 3;

    cout << findPages(arr, n, m) << endl;
}