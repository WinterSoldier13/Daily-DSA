#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;


//<><><><><><><><><><><><><><><SUBSET SUM><><><><><><><><><><><><><><>><><><><><><><><><><><><><>
//RECURSION
bool findSum(vector<int> arr, int l, int sum)
{
    if(sum==0)
    {
        return true;
    }

    if(l==0)
    {
        return false;
    }
    if(arr[l-1]<=sum)
    {
        return (findSum(arr,l-1,sum-arr[l-1]) or findSum(arr,l-1,sum));
    }
    else
    {
        return findSum(arr,l-1,sum);
    }
    

}


//DYNAMIC
bool dynamic(vector<int> arr, int sum)
{
    int l = arr.size();
    int dp[l+1][sum+1];

    for(int i=0;i<=sum;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=l;i++)
    {
        dp[i][0] = 1;
    }

    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i]<=sum)
            {
                dp[i][j] = max(dp[j-arr[i]][i-1], dp[j][i-1]);
            }
            dp[i][j] = dp[j][i-1];
        }
        
    }

    return dp[l][sum];
}



int main()
{
    vector<int> arr{1,5,11,3};

    int sum=0;
    for(auto c: arr)
    sum+=c;

    if(sum%2!=0)
    cout<<false<<endl;

    else
    {
        if(findSum(arr,arr.size()-1,sum/2))
        cout<<"True"<<endl;
        else
        {
            cout<<"False"<<endl;
        }
        
    }
    

    return 0;
}