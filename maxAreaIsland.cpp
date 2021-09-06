class Solution
{
public:
    int recurse(vector<vector<int>> &arr, int i, int j)
    {
        int rows = arr.size();
        int cols = arr[0].size();

        if (i < 0 or j < 0 or i >= rows or j >= cols or arr[i][j] != 1)
        {
            return 0;
        }
        arr[i][j] = -1;
        return 1 + recurse(arr, i - 1, j) + recurse(arr, i, j + 1) + recurse(arr, i + 1, j) + recurse(arr, i, j - 1);
    }

    int counter(vector<vector<int>> &arr)
    {
        int area = 0;
        int rows = arr.size();
        int cols = arr[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (arr[i][j] == 1)
                {
                    area = max(area, recurse(arr, i, j));
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        return counter(grid);
    }
};