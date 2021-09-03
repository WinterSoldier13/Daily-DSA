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
    #define ll long long
private:
    unordered_map<int, unordered_map<int,ll> > sumCache; 
    unordered_map<int, unordered_map<int,ll> > recursionCache; 

    ll getArraySum(vector<int> arr, int start, int end)
    {
        if (sumCache.find(start) != sumCache.end() and sumCache[start].find(end) != sumCache[start].end())
        {
            return sumCache[start][end];
        }
        ll sum = 0;
        for (int i = start; i <= end; i++)
        {
            sum += arr[i];
        }
        return sumCache[start][end] = sum;
    }

    ll recurse(vector<int> arr, int n, int k)
    {
        if (recursionCache.find(n) != recursionCache.end() and recursionCache[n].find(k) != recursionCache[n].end())
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
        ll bestValue = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            ll result = max(recurse(arr, i, k - 1), getArraySum(arr, i, n - 1));
            bestValue = min(bestValue, result);
        }
        return recursionCache[n][k] = bestValue;
    }

public:
    Solution()
    {
        sumCache.clear();
        recursionCache.clear();
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
