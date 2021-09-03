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
#define MOD 1000000007
#define object Solution ob

class Solution
{
public:
#define MOD 1000000007
    unordered_map<int, int> cacheMem;
    Solution()
    {
        cacheMem.clear();
        cacheMem[1] = 1;
        cacheMem[2] = 2;
    }
    int nthPoint(int n)
    {
        if (cacheMem.find(n) != cacheMem.end())
        {
            return cacheMem[n];
        }
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            if (cacheMem.find(i) != cacheMem.end())
            {
                dp[i] = cacheMem[i];
            }
            else
            {
                dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD;
                cacheMem[i] = dp[i];
            }
        }

        return dp[n];
    }
};

int main()
{
    fast_cin();

    int n;
    cin >> n;

    object;
    cout << ob.nthPoint(n) << endl;
    return 0;
}
