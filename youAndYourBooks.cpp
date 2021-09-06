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


int max_Books(int arr[], int n, int k)
{
    vector<int> dp(n, 0);

    dp[0] = arr[0]<=k ? arr[0] : 0;

    for(int i=1;i<n;i++)
    {
        if(arr[i] <= k)
        {
            dp[i] = dp[i-1] + arr[i];
        }
        else
        {
            dp[i] = 0;
        }    
    }

    return *max_element(dp.begin(), dp.end());
}

int main()
{
    return 0;
}