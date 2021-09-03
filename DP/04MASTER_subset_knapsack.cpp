#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;

int totalSum(vector<int> arr)
{
    int sum=0;
    for(int x:arr)
    sum+=x;
    return sum;
}

//RECURSIVE
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
// <><><><><><><><><><><><><><><><><><FIND SUM<><><><><><><><><><><><><><><><><><<><><><><><><><
bool dynamic(vector<int> arr, int sum)
{
    int l= arr.size();
    int dp[l+1][sum+1];

    for(int i=0;i<=sum;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=l;i++)
    {
        dp[i][0]=1;
    }
    
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = max(dp[i-1][j-arr[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }
    return dp[l][sum];
}


// <><><><><><><><><><><><><><><><><><>><FIND EQUAL SUBSET SUM<><><><><><><><><><><><><><><><><><><><><><><

//CONCEPT: If their exist two partitions such that their sum is equal... let one be S1 and other be S2.... total = S = S1+S2;
// Now for equal S1 = S2 => S = 2k => S is even.... i.e S = S1+S1 is also even
// If S is odd this is not possible return 0
// Else do S/2 because S1 = S/2... and if S1 exist in the array then their exist two subsets with equal sum
// Use the above program to do so.


// <><><><><><><><><><><><><><><><><><>><FIND MIN DIFF OF SUB ARRAY<><><><><><><><><><><><><><><><><><><><><><><

// CONCEPT: Now we need to find the minimum difference between the sum of two subset is an Array
// i.e |S1-S2| = min... We know that total S1+S2 = S 
// => we need to minimize S2 - S1 ...assuming S2>S1
// => we need to minimize S-S1 -S1 
// => minimum of S - 2*S1
// => Now the range of S1 is from 0 to S ..... S1 can be min for{} and max for all elements
// => Let's say total sum S =10 and S1 =2 ... then S2 =8... similarly for S1 =3 s2 =7 .... s1=4 s2=6 ... and so on...
// THe point is for every S1 on the numberline from 0 to S their exist a number for S2 on the same number line
// Therefore we can constrain the value of S1 from 0 to S/2
// Now for these values not all will be the sum of a subset from arr ex. {1,5,7} will never have 4 as a sum of subset
// Hence Check for 0 to S/2 which numbers are possible as subset from the above program 
// In the above program dp[last_row][N] will give 1 if N can be a sum of subset.. then return the minimum

//LET's IMPLEMENT IT once AGAIN

int minSubSum(vector<int> arr)
{
    int total_sum = totalSum(arr);
    int l = arr.size();

    int dp[l+1][total_sum+1];

    for(int i=0;i<=total_sum;i++)
    {
        dp[0][i] =0; // If len=0 then no sum is possible
    }
    for(int i=0;i<=l;i++)
    {
        dp[i][0] =1; // if sum=0 then it will have solution for {}
    }

    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=total_sum;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = max( dp[i-1][j-arr[i-1]], dp[i-1][j] );
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }
    vector<int> possibleS1;
    
    for(int i=total_sum/2;i>=0;i--)
    {
        if(dp[l][i]==1)
        {
            possibleS1.push_back(i);
        }
    }

    int min_ =INT32_MAX;
    for(int x: possibleS1)
    {
        min_ = min(min_, (total_sum-2*x));
    }

    return min_;
}


int main()
{
    vector<int> arr{1,6,11,5};
    int sum =18;
    cout<<findSum(arr,arr.size(),sum)<<endl;
    cout<<dynamic(arr,sum)<<endl;

    return 0;
}