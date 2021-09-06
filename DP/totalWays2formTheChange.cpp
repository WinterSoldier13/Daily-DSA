#include<iostream>
#include<bits/stdc++.h>

using namespace std;


//RECURSIVE 

int totalWays(vector<int> arr, int l, int sum)
{
    if(sum==0)
    {
        return 1;
    }
    if(l==0)
    {
        return 0;
    }

    if(arr[l-1]<=sum)
    {
        return totalWays(arr,l,sum-arr[l-1]) + totalWays(arr,l-1,sum);
    } 
    else
    {
        return totalWays(arr,l-1,sum);
    }
}

//Dynamic Programming

int dynamic(vector<int> arr, int sum)
{
    int l=arr.size();

    int dp[l+1][sum+1];

    for(int i=0;i<=sum;i++)
    {
        dp[0][i] = 0;
    }

    for(int i=0;i<=l;i++)
    {
        dp[i][0] = 1;
    }
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i][j-arr[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[l][sum];

}



// O(N)space
int count( int S[], int m, int n ) 
{ 
    // table[i] will be storing the number of solutions for 
    // value i. We need n+1 rows as the table is constructed 
    // in bottom up manner using the base case (n = 0) 
    int table[n+1]; 
  
    // Initialize all table values as 0 
    memset(table, 0, sizeof(table)); 
  
    // Base case (If given value is 0) 
    table[0] = 1; 
  
    // Pick all coins one by one and update the table[] values 
    // after the index greater than or equal to the value of the 
    // picked coin 
    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            table[j] += table[j-S[i]]; 
  
    return table[n];
}

int main()
{
    vector<int> arr{1,2,3,4};
    int sum=5;
    cout<<totalWays(arr,arr.size(),sum)<<endl;
    cout<<dynamic(arr,sum)<<endl;
    return 0;
}