#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int totalPossibleWays;


bool recurse(vector<vector<int>> &arr, int i, int j)
{
    int rows = arr.size();
    int cols = arr[0].size();
    if(dp[i][j])
    {
        return true;
    }

    if (i == rows - 1 and j == cols - 1)
    {
        // totalPossibleWays++;
        
        return dp[i][j] =true;
    }
    if (i < 0 or j < 0 or i >= rows or j >= cols or arr[i][j] != 0)
    {
        // dp[i][j] = 0;
        if(i>=0 and i<rows and j>=0 and j<cols)
        {
            return dp[i][j] = false;
        }
        return false;
    }
    arr[i][j] = -1;
    dp[i][j] = recurse(arr, i, j + 1) or recurse(arr, i + 1, j);
    if(true) 
    {
        totalPossibleWays++;
    }
    arr[i][j] = 0;
    return dp[i][j];
}

THis is DFS based
// int uniquePathsWithObstacles(vector<vector<int>> &arr)
// {
//   
//     if (arr.size() == 0 or arr[arr.size() - 1][arr[0].size() - 1] == 1)
//     {
//         return 0;
//     }
//     if (arr.size() == 1 and arr[0].size() == 1)
//     {
//         return !arr[0][0];
//     }
//     recurse(arr, 0, 0);
//     return totalPossibleWays;
// }

int uniquePathsWithObstacles(vector<vector<int>> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();

    vector<int> t(cols,0);
    vector<vector<int>> dp(rows, t);

    // if first or last block contains obstacle
    if(arr[0][0] == 1)
    {
        return 0;
    }
    if(arr.size() == 0 or (arr[arr.size()-1][arr[0].size()-1] == 1) )
    {
        return 0;
    }

    dp[0][0] = 1;
    // move right and give to number of ways possible
    for(int i=1;i<cols;i++)
    {
        if(arr[0][i] == 1)
        {
            dp[0][i] = 0;
        }
        else
        {
            dp[0][i] = dp[0][i-1];
        }
    }

    // move down and give to number of ways possible
    for(int i=1;i<rows;i++)
    {
        if(arr[i][0] == 1)
        {
            dp[i][0] = 0;
        }
        else
        {
            dp[i][0] = dp[i-1][0];
        }
    }

    
    for(int i=1;i<rows;i++)
    {
        for(int j=1;j<cols;j++)
        {
            // if obstacle
            if(arr[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                // no of ways to reach the current cell = no of ways to reach the up cell + no of ways to reach the left cell
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            
        }
    }
    return dp[rows-1][cols-1];
}

int main()
{
    vector<vector<int>> arr{{0, 0, 0},
                            {0, 1, 0},
                            {0, 0, 0}};

    cout << uniquePathsWithObstacles(arr) << endl;
}