#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli unsigned long long int

void dynamic(vector<vector<int>> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();

    vector<vector<int>> dp(rows, vector<int> (cols));

    dp[rows-1][cols-1] = arr[rows-1][cols-1]>0?1:abs(arr[rows-1][cols-1])+1;

    // Last col
    for(int i= rows-2;i>=0;i--)
    {
        dp[i][cols-1] = max(dp[i+1][cols-1] - arr[i][cols-1], 1);
    }
    // last row
    for(int i = cols-2;i>=0;i--)
    {
        dp[rows-1][i] = max(dp[rows-1][i+1] - arr[rows-1][i], 1);
    }

    for(int i=rows-2;i>=0;i--)
    {
        for(int j=cols-2;j>=0;j--)
        {
            int min_ = min(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = max(min_ - arr[i][j], 1);
        }
    }
    cout<<dp[0][0]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> arr(m, vector<int> (n,0));
        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }

        dynamic(arr);

    }
}
