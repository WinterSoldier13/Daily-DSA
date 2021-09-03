#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;

//RECURSIVE 
int maxProfit(vector<int> wt, vector<int> profit, int sum, int ind)
{
    if(ind==0 or sum==0)
    {
        return 0;
    }

    if(wt[ind-1]<=sum)
    {
        return max(profit[ind-1]+maxProfit(wt,profit,sum-wt[ind-1], ind-1), maxProfit(wt,profit,sum,ind-1));
    }
    else
    {
        return maxProfit(wt,profit,sum,ind-1);
    }

}


//DYNAMIC

int dynamic(vector<int> wt, vector<int> profit, int sum)
{
    int l = wt.size();

    int dp[l+1][sum+1];

    for(int i =0;i<=sum;i++)
    {
        dp[0][i] =0;
    }
    for(int i=0;i<=l;i++)
    {
        dp[i][0]=0;
    }

    for(int len=1;len<=l;len++)
    {
        for(int s=1;s<=sum;s++)
        {
            if(wt[len-1]<=s)
            {
                dp[len][s] = max(profit[len-1]+dp[len-1][s-profit[len-1]], dp[len-1][s]);
            }
            else
            {
                dp[len][s] = dp[len-1][s];
            }
            
        }
    }
    return dp[l][sum];
}




int main()
{
    vector<int> wt;
    vector<int> profit;

    return 0;
}