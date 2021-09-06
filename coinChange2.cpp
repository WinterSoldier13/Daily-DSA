#include <bits/stdc++.h>
using namespace std;

int change(int amount, vector<int> &coins)
{
    int  l = coins.size();

    vector<int> t(amount+1);
    vector<vector<int>> dp(l+1,t);

    // When the amount is zero then possible ways =1
    for(int i=0;i<=l;i++)
    {
        dp[i][0] = 1;
    }
    // When the coins given are zero then total ways = 0 except for the 0,0 index
    for(int i=1;i<=amount;i++)
    {
        dp[0][i] = 0;
    }
    dp[0][0] = 1;

    for(int i=1;i<=l;i++)
    {
        int coin = coins[i-1];
        for(int j=1;j<=amount;j++)
        {
            if(coin<=j)
            {
                // dp[i][j] = totalPossibleWays(if I don't use the current coin(i.e just move one row above) + if I use the current coin(then it is subtracted from the current amount))
                dp[i][j] = dp[i-1][j] + dp[i][j-coin];
            }
            else
            {
                // If my given coin is greater than the amount to be formed, then I just ignore it, i.e I move one row above
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(auto x: dp)
    {
        for(auto c: x)
        cout<<c<<" ";
        cout<<endl;
    }
    return dp[l][amount];
}

int main()
{
    vector<int> coins{1,2,5};
    int amount = 5;

    cout<<change(amount, coins)<<endl;
}
