#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    void changeToMinus(vector<vector<int>> &grid, int r, int c)
{
    int rows = grid.size();
    int cols = grid[0].size();

    for(int i=0;i<rows;i++)
    {
        if(grid[i][c]!=0)
        {
            grid[i][c] = INT16_MIN;
        }
    }
    for(int i=0;i<cols;i++)
    {
        if(grid[r][i]!=0)
        {
            grid[r][i]=INT16_MIN;
        }
    }

}
void minusToPlus(vector<vector<int>> &grid)
{
    int rows= grid.size();
    int cols = grid[0].size();

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(grid[i][j]==INT16_MIN)
            {
                grid[i][j]=0;
            }
        }
    }
}



void setZeroes(vector<vector<int>>& grid) 
{
    int rows=grid.size();
    int cols = grid[0].size();

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(grid[i][j]==0)
            {
                changeToMinus(grid,i,j);
            }
        }
    }
    minusToPlus(grid);
        
}
};