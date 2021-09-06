#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;


int longestIncreasingSub(vector<int> arr, int l)
{
    if(l==0)
    {
        return 0;
    }
    if(arr[l-1]>arr[l-2])
    {
        return 1+ longestIncreasingSub(arr,l-1);
    }
    else
    {
        return longestIncreasingSub(arr,l-1);
    }
}



// DYNAMIC

int dynamic(vector<int> arr)
{
    int l = arr.size();
    // THe number of changing values in recursion is 1 i.e l therefore dp will be 1D

    vector<int> dp(l+1,1);
    dp[0]=0;
    dp[1] =1;

    for(int i=2;i<=l;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i-1])
            {
                dp[i] = max(dp[i],dp[j+1]+1);
            }
        }
    }
    return dp[l];
}

int main()
{
    vector<int> arr {50, 2};
    int l = arr.size();

    cout<<longestIncreasingSub(arr,l)<<endl;
    cout<<dynamic(arr)<<endl;

    return 0;
}