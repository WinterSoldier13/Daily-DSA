
class Solution
{
public:
    void landToWater(vector<vector<int>> &grid, int i, int j)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 or j < 0 or i >= rows or j >= cols or grid[i][j] != 0)
        {
            return;
        }

        grid[i][j] = 1;

        landToWater(grid, i - 1, j);
        landToWater(grid, i, j + 1);
        landToWater(grid, i + 1, j);
        landToWater(grid, i, j - 1);
    }
    
    void landToWaterAtEdges(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < cols; i++)
        {
            if (grid[0][i] == 0)
            {
                landToWater(grid, 0, i);
            }
        }
        for (int i = 0; i < cols; i++)
        {
            if (grid[rows - 1][i] == 0)
            {
                landToWater(grid, rows - 1, i);
            }
        }
        for (int i = 0; i < rows; i++)
        {
            if (grid[i][0] == 0)
            {
                landToWater(grid, i, 0);
            }
        }
        for (int i = 0; i < rows; i++)
        {
            if (grid[i][cols - 1] == 0)
            {
                landToWater(grid, i, cols - 1);
            }
        }
    }

    void countLandHelper(vector<vector<int>> &grid, int i, int j)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 or j < 0 or i >= rows or j >= cols or grid[i][j] != 0)
        {
            return;
        }
        grid[i][j] = -1;
        countLandHelper(grid, i - 1, j);
        countLandHelper(grid, i, j + 1);
        countLandHelper(grid, i + 1, j);
        countLandHelper(grid, i, j - 1);
    }

    int countLand(vector<vector<int>> &grid)
    {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 0)
                {
                    count++;
                    countLandHelper(grid, i, j);
                }
            }
        }
        return count;
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
        {
            return 0;
        }
        landToWaterAtEdges(grid);

        return countLand(grid);
    }
};