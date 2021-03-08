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
private:
    vector<vector<int>> sumCache;
    vector<vector<int>> recursionCache;

    int getArraySum(vector<int> arr, int start, int end)
    {
        if (sumCache[start][end] != -1)
        {
            return sumCache[start][end];
        }
        int sum = 0;
        for (int i = start; i <= end; i++)
        {
            sum += arr[i];
        }
        return sumCache[start][end] = sum;
    }

    int recurse(vector<int> arr, int n, int k)
    {
        if (recursionCache[n][k] != -1)
        {
            return recursionCache[n][k] = recursionCache[n][k];
        }
        if (n == 1)
        {
            return recursionCache[n][k] = arr[0];
        }
        if (k == 1)
        {
            return recursionCache[n][k] = getArraySum(arr, 0, n - 1);
        }
        int bestValue = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            int result = max(recurse(arr, i, k - 1), getArraySum(arr, i, n - 1));
            bestValue = min(bestValue, result);
        }
        return recursionCache[n][k] = bestValue;
    }

public:
    Solution()
    {
        sumCache = vector<vector<int>>(1000, vector<int>(1000, -1));
        recursionCache = vector<vector<int>>(1000, vector<int>(1000, -1));
    }
    void solve(vector<int> arr, int n, int k)
    {
        cout << recurse(arr, n, k) << endl;
    }
};

int main()
{
    fast_cin();

    getT()
    {
        int k, n;
        cin >> k >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;

        ob.solve(arr, n, k);
    }
    return 0;
}
