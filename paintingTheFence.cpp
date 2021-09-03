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


// https://www.youtube.com/watch?v=ju8vrEAsa3Q

class Solution{
    public:
    #define ll long long
    #define MOD 1000000007
    long long countWays(int n, int k)
    {
        vector<vector<ll>> dp(3, vector<ll> (n+1, 0));

        if(n == 1)
        {
            return k;
        }
        if(k == 1)
        {
            return 1;
        }

        dp[0][2] = k;
        dp[1][2] = k*(k-1);
        dp[2][2] = dp[0][2] + dp[1][2];

        for(int i=3;i<=n;i++)
        {
            dp[0][i] = dp[1][i-1]%MOD;
            dp[1][i] = (dp[2][i-1]%MOD * (k-1))%MOD;
            dp[2][i] = (dp[0][i] + dp[1][i])%MOD;
        }

        return dp[2][n];

    }
};

int main()
{
    fast_cin();
    int arr[] = {8, 15  };
    int n = sizeof(arr) / sizeof(arr[0]);

    object;
    return 0;
}
