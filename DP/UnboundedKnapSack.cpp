#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;

// UNBOUNDED KNAPSACK

// RECURSION
int recurse(vector<int> wgt, vector<int> profit, int l, int sum)
{
    if(l==0)
    {
        return 0;
    }
    if(sum==0)
    {
        return 0;
    }

    if(wgt[l-1]<=sum)
    {
        return max(profit[l-1] + recurse(wgt,profit,l,sum-wgt[l-1]), recurse(wgt,profit,l-1,sum));

    }
    else
    {
        return recurse(wgt,profit,l-1,sum);
    }
}


//DYNAMIC 
int dynamic(vector<int> wgt, vector<int> profit, int sum)
{
    int l =wgt.size();
    int dp[l+1][sum+1];

    for(int i=0;i<=sum;i++)
    {
        dp[0][i] = 0;
    }
    for(int i=0;i<=l;i++)
    {
        dp[i][0] = 0;
    }

    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(wgt[i-1]<=j)
            {
                dp[i][j] = max(profit[i-1]+dp[i][j-wgt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }
    return dp[l][sum];
}

int main()
{
    int sum=8;
    vector<int> val{10, 40, 50, 70};
    vector<int> wgt{1, 3, 4, 5};

    cout<<recurse(wgt,val,wgt.size(), sum)<<endl;
    cout<<dynamic(wgt,val, sum)<<endl;
}