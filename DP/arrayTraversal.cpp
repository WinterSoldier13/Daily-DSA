#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;


//RECURSIVE
int minP(vector<vector<int>> arr, int i, int j)
{
    if(i==0 and j==0)
    {
        return arr[0][0];
    }
    int res1=INT32_MAX,res2 = INT32_MAX-1;
    if(i>0)
    {
        res1 = arr[i][j] + minP(arr,i-1,j);  // Move UP
    }
    if(j>0)
    {
        res2 = arr[i][j] + minP(arr,i,j-1); // MOve LEft
    }

    return min(res1,res2);
}

//dynamic
int dynamic(vector<vector<int>> arr)
{
    int rows = arr.size();
    int cols = arr[0].size();
    vector<vector<int>> dp;
    vector<int> temp;
    for(int i=0;i<cols;i++)
    temp.push_back(0);
    for(int i=0;i<rows;i++)
    {
        dp.push_back(temp);
    }



    dp[0][0] = arr[0][0];

    for(int i=1;i<cols;i++)
    {
        dp[0][i] = dp[0][i-1] + arr[0][i];
    }
    for(int i=1;i<rows;i++)
    {
        dp[i][0] = dp[i-1][0] + arr[i][0];
    }


    for(int i=1;i<rows;i++)
    {
        for(int j=1;j<cols;j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + arr[i][j];
        }
    }


     for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }



    return dp[dp.size()-1][dp[0].size()-1];




}

int main()
{
    vector<vector<int>> arr{{1,3,2},
                            {4,3,1},
                            {5,1,1}};
    cout<<minP(arr,2,2)<<endl;
    cout<<dynamic(arr)<<endl;
    return 0;

}