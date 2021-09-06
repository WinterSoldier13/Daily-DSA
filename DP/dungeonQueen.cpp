#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int dynamic(vector<vector<int>> arr)
{
    int rows = arr.size();
    int cols = arr[0].size();
    vector<vector<int>> dp;
    vector<int> temp(cols,0);
    for(int i=0;i<rows;i++)
    {
        dp.push_back(temp);
    }
    dp[rows-1][cols-1] = arr[rows-1][cols-1]>0?1:abs(arr[rows-1][cols-1])+1;

    for(int i =cols-2;i>=0;i--)
    {
        dp[rows-1][i] = dp[rows-1][i+1] - arr[rows-1][i];
        if(dp[rows-1][i]<=0)
        dp[rows-1][i]=1;
    }

    for(int i=rows-2;i>=0;i--)
    {
        dp[i][cols-1] = dp[i+1][cols-1] - arr[i][cols-1];
        if(dp[i][cols-1]<0)
        dp[i][cols-1]=1;
        
    }

    for(int i=rows-2;i>=0;i--)
    {
        for(int j=cols-2;j>=0;j--)
        {
            dp[i][j] = min(dp[i+1][j]-arr[i][j], dp[i][j+1]-arr[i][j]);

            if(dp[i][j]<0)
            dp[i][j] =1;
        }
    }
    

    cout<<endl;
    for(auto x: dp)
    {
        for(int c:x)
        cout<<c<<" ";
        cout<<endl;
    }
    return dp[0][0];
}

int main()
{
    vector<vector<int>> arr{{-2,-3,3},
                            {-5,-10,1},
                            {10,30,-5}};
    cout<<"Min health required: "<<dynamic(arr)<<endl;

    return 0;
}