#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli long long int
#define pii pair<int, int>
#define endl '\n'
#define printArr(arr)     \
    for (auto x : arr)    \
        cout << x << " "; \
    cout << endl;
#define printHashmap(hashmap)                                  \
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) \
    {                                                          \
        cout << it->first << " " << it->second << endl;        \
    }
#define print2DArray(arr)     \
    for (auto x : arr)        \
    {                         \
        for (auto c : x)      \
            cout << c << " "; \
        cout << endl;         \
    }

class Solution
{
public:
    int maxGold(int n, int m, vector<vector<int>> arr)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = arr[i][0];
        }

        for (int j = 1; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i - 1 >= 0)
                {
                    dp[i][j] = max(dp[i][j], arr[i][j] + dp[i - 1][j - 1]);
                }

                dp[i][j] = max(dp[i][j], arr[i][j] + dp[i][j - 1]);

                if (i + 1 < n)
                {
                    dp[i][j] = max(dp[i][j], arr[i][j] + dp[i + 1][j - 1]);
                }
            }
        }
        int maxEle = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxEle = max(maxEle, dp[i][m - 1]);
        }

        print2DArray(dp);
        cout<<maxEle<<endl;
        return maxEle;
    }
};

int main()
{
    fast_cin();

    vector<vector<int>> arr{{1, 3, 3}, {2, 1, 4}, {0, 6, 4}};
    int n = 3;
    int m = 3;

    Solution ob;
    ob.maxGold(n, m, arr);
    return 0;
}
