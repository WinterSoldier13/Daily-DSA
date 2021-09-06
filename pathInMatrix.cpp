#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

int dynamic(vector<vector<int>> &arr)
{
    int l = arr.size();
    vector<int> t(l,0);
    vector<vector<int>> dp(l,t);

    for(int i=0;i<l;i++)
    {
        dp[0][i] = arr[0][i];
    }

    for(int i=1;i<l;i++)
    {

        for(int j=0;j<l;j++)
        {
            if(j==0)
            {
                dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
            }
            if(j==l-1)
            {
                dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
            }
            else
            {
                dp[i][j] = arr[i][j] + max(dp[i-1][j], max( dp[i-1][j-1], dp[i-1][j+1] ) );

            }
        }
    }


    return *max_element(dp[l-1].begin(), dp[l-1].end());
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> t(n,0);
        vector<vector<int>> arr(n,t);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }

        cout<<dynamic(arr)<<endl;

    }
}
