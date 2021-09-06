#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

int getRightSubTreeIndex(vector<int> &arr, int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] > val)
        {
            return i;
        }
    }
    return end + 1;
}

bool isAllSmaller(vector<int> &arr, int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] > val)
            return false;
    }
    return true;
}

bool isAllLarger(vector<int> &arr, int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < val)
        {
            return false;
        }
    }
    return true;
}

bool recurse(vector<int> &arr, int start, int end)
{
    if (end - start + 1 <= 0)
    {
        return true;
    }
    int root = arr[start];
    int rightIndex = getRightSubTreeIndex(arr, start, end, root);
    int leftSubTreeSize = rightIndex - start - 1;
    int rightSubTreeSize = end - rightIndex + 1;

    if (isAllSmaller(arr, start + 1, rightIndex - 1, root) and isAllLarger(arr, rightIndex, end, root) and recurse(arr, start + 1, rightIndex - 1) and recurse(arr, rightIndex, end))
    {
        return true;
    }
    return false;
}

void solve(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;
    if (recurse(arr, start, end))
        cout << 1 << endl;
    else
        cout << 0 << endl;
}

int main()
{
    fast_cin();
    cin.tie(NULL);

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

        solve(arr);
    }
    return 0;
}