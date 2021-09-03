#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows,cols;
    
    
    void helper(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0||i>=rows||j<0||j>=cols||grid[i][j]=='0')
            return;
            
        grid[i][j]='0';

        helper(grid,i+1,j);
        helper(grid,i,j+1);
        helper(grid,i,j-1);
        helper(grid,i-1,j);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty())
            return 0;
        int count =0;
        rows = grid.size();
        cols = grid[0].size();
        
        if(rows==0 && cols==0)
            return 0;
        
        for(int i =0;i<rows;++i)
        {
            for(int j =0;j<cols;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    helper(grid,i,j);
                }
            }
        }
        return count;
        
    }
};