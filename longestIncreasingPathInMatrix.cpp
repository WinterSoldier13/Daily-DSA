class Solution
{
private:
    int solve(vector<vector<int>> &mat, vector<vector<int>> &dp, int x, int y)
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};

        dp[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + xMove[i];
            int ny = y + yMove[i];

            if (0 <= nx && nx < mat.size() && 0 <= ny && ny < mat[nx].size() && mat[x][y] < mat[nx][ny])
                dp[x][y] = max(dp[x][y], 1 + solve(mat, dp, nx, ny));
        }
        return dp[x][y];
    }

public:
    int longestIncreasingPath(vector<vector<int>> &mat)
    {
        if (mat.size() == 0 || mat[0].size() == 0)
            return 0;
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dp[i][j] == -1)
                    res = max(res, solve(mat, dp, i, j));
        return res;
    }
};