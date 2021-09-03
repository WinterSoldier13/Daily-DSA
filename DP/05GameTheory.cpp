#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
public:
    vector<vector<int>> recursionCache;

    Solution()
    {
        recursionCache = vector<vector<int>>(1001, vector<int>(1001, -1));
    }
    int recurse(int arr[], int start, int end)
    {
        if (recursionCache[start][end] != -1)
        {
            return recursionCache[start][end] = recursionCache[start][end];
        }
        if (end - start == 1)
        {
            return recursionCache[start][end] = max(arr[start], arr[end]);
        }
        if (end - start == 0)
        {
            return recursionCache[start][end] = arr[start];
        }

        return recursionCache[start][end] = max(arr[start] + min(recurse(arr, start + 1, end - 1), recurse(arr, start + 2, end)), arr[end] + min(recurse(arr, start + 1, end - 1), recurse(arr, start, end - 2)));
    }
};
int maxCoins(int arr[], int N)
{
    Solution ob;
    return ob.recurse(arr, 0, N - 1);
}
int main()
{
    fast_cin();

    return 0;
}