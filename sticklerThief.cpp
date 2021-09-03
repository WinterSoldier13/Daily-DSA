#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

int solve(vector<int> &arr)
{
    int l = arr.size();
    if (l == 1)
    {
        return arr[0];
    }
    vector<int> dp(l, 0);

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < l; i++)
    {
        dp[i] =  max(dp[i-2] + arr[i], dp[i-1]);
    }
    return dp[l-1];
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
        cin>>n;

        vector<int> arr(n);

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr)<<endl;
    }
    return 1;
}