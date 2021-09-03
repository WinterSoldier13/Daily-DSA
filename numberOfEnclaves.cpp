class Solution {
public:
    //Leet 1020
    
    void recurse(vector<vector<int>> &grid, int i, int j)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(i<0 or j<0 or i>=rows or j>=cols or grid[i][j]!=1)
        {
            return;
        }
        grid[i][j] = 0;
        recurse(grid,i,j+1);
        recurse(grid,i-1,j);
        recurse(grid,i,j-1);
        recurse(grid,i+1,j);
        
    }
    
    void findEdges(vector<vector<int>> &grid)
    {
        int rows=grid.size();
        int cols = grid[0].size();
        
        for(int i=0;i<cols;i++)
        {
            if(grid[0][i] == 1)
            {
                recurse(grid, 0,i);
            }
        }
        
        for(int i=0;i<cols;i++)
        {
            if(grid[rows-1][i]==1)
            {
                recurse(grid, rows-1, i);
            }
        }
        
        for(int i=0;i<rows;i++)
        {
            if(grid[i][0]==1)
            {
                recurse(grid,i,0);
            }
        }
        
        for(int i=0;i<rows;i++)
        {
            if(grid[i][cols-1]==1)
            {
                recurse(grid,i,cols-1);
            }
        }
    }
    
    int countOne(vector<vector<int>>&arr)
    {
        int rows = arr.size();
        int cols = arr[0].size();
        
        int count=0;
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(arr[i][j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
    
    
    
    
    int numEnclaves(vector<vector<int>>& grid) 
    {
        findEdges(grid);
        return countOne(grid);
        
        
        
    }
};