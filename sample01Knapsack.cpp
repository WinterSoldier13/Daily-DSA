#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// A sample code of 0-1Knapsack

int recursive(vector<int> wgt, vector<int> profit, int sum, int index)
{
    if (index == 0)
    {
        return 0;
    }
    if (wgt[index - 1] <= sum)
    {
        return max(profit[index - 1] + recursive(wgt, profit, sum - wgt[index - 1], index - 1), recursive(wgt, profit, sum, index - 1));
    }
    else
    {
        return recursive(wgt, profit, sum, index - 1);
    }
}

int dynamic(vector<int> wgt, vector<int> profit, int sum)
{
    int l2 = profit.size();
    int l1 = wgt.size();

    vector<int> t(l2 + 1);
    vector<vector<int>> dp(l1 + 1, t);

    for (int i = 0; i <= l1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= l2; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (wgt[i - 1] <= j)
            {
                dp[i][j] = max(profit[i - 1] + dp[i - 1][j - wgt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[l1][l2];
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, sum;
        scanf("%d", &n);
        scanf("%d", &sum);
        vector<int> profit(n, 0);
        vector<int> wgt(n, 0);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &profit[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &wgt[i]);
        }

        int l2 = profit.size();
        int l1 = wgt.size();

        vector<int> t(l2 + 1);
        vector<vector<int>> dp(l1 + 1, t);

        for (int i = 0; i <= l1; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= l2; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                if (wgt[i - 1] <= j)
                {
                    dp[i][j] = max(profit[i - 1] + dp[i - 1][j - wgt[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout<<dp[l1][l2]<<endl;
    }
}