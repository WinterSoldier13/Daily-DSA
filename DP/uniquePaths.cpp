#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// https://www.interviewbit.com/problems/unique-paths-in-a-grid/

int grid(vector<vector<int>> arr, int i, int j)
{
    if(i==0 and j==0)
    {
        return 1;
    }
    int res1=0;
    int res2 =0;

    if(i>0)
    {
        if(arr[i-1][j]==0)
        {
            res1 =  grid(arr,i-1,j);
        }
    }
    if(j>0)
    {
        if(arr[i][j-1]==0)
        {
            res2 = grid(arr,i,j-1);
        }
    }

    return res1+res2;
}

//DYNAMIC .. WOW i don't know how it came into my mind

// Always start thinking by smaller cases... like start from grid at 0,0 the total paths to reach this grid from 0,0 is 1
// then go right if 1 then total ways to reach this from 0,0 will  also be 1 ... I mean it's just an 1D path right now
// but If while going right you encounter any obstacle.. then the total ways to reach that obstacle and beyond from 0,0 become 0
// Same for vertically down
// now form 1,1 total path = path_from_above + path_at_left side

int dynamic(vector<vector<int>> arr)
{
    vector<vector<int>> dp;
    int rows = arr.size();
    int cols = arr[0].size();

    vector<int> temp(cols,0);

    for(int i=0;i<rows;i++)
    {
        dp.push_back(temp);
    }
    bool flag = true;
    for(int i=0;i<cols;i++)
    {
        if(arr[0][i] == 0 and flag)
        {
            dp[0][i] = 1;
        }
        else
        {
            flag = false;
            break;
        }
        
    }
    for(int i=0;i<rows;i++)
    {
        if(arr[i][0]==0)
        {
            dp[i][0] = 1;
        }
        else
        {
            break;
        }
        
    }

    for(int i=1;i<rows;i++)
    {
        for(int j=1;j<cols;j++)
        {
            if(arr[i][j]==0)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }



    for(auto x: dp)
    {
        for(int c: x)
        {
            cout<<c<<" ";
        }
        cout<<endl;
    }

    return dp[rows-1][cols-1];


    return 0;
}


int main()
{
    vector<vector<int>> arr{{0,0,0,0},
                            {0,0,1,0},
                            {0,0,0,0}};
    
    cout<<grid(arr, arr.size()-1, arr[0].size()-1)<<endl;
    cout<<dynamic(arr)<<endl;

    return 0;
}