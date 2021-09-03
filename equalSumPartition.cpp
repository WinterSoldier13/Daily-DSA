#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;


// A sample code of subsetSum
bool recurse(vector<int> arr, int sum_, int index)
{
    if(sum_ == 0)
    {
        return true;
    }
    if(index == 0)
    {
        return false;
    }
    if(arr[index-1]<=sum_)
    {
        return max( recurse(arr,sum_-arr[index-1], index-1), recurse(arr,sum_,index-1) );
    }
    else
    {
        return recurse(arr, sum_, index-1);
    }
    
}


bool sumExistsInTheSet(vector<int> &arr, int sum_)
{
    int l = arr.size();
    vector<int> t(sum_+1,0);
    vector<vector<int>> dp(l+1, t);
    
    for(int i=0;i<=l;i++)
    {
        for(int j=0;j<=sum_;j++)
        {
            if(j==0)
            {
                dp[i][j] = 1;
            }
            if(i==0)
            {
                dp[i][j]=0;
            }
        }
    }
    dp[0][0] = 0;

    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=sum_;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j] = max(dp[i-1][j-arr[i-1]], dp[i-1][j]);
            else
            {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }

    return dp[l][sum_];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n,0);
        int totalSum = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            totalSum+=arr[i];
        }
        cout<<totalSum<<endl;

        if(totalSum%2!=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            if(sumExistsInTheSet(arr, totalSum/2))
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
            
        }
        

    }
}

// int main()
// {
//     vector<int> arr{1,5,1,1,4};
//     int sum_ = 13;
//     cout<<recurse(arr,sum_, arr.size());
// }