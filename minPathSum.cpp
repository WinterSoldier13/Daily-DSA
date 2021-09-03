class Solution {
public:
int minPathSum(vector<vector<int>>& arr) 
{
    int rows = arr.size();
    int cols = arr[0].size();
    vector<int> t(cols, 0);
    vector<vector<int>> dp(rows, t);

    dp[0][0] = arr[0][0];
    for(int i=1;i<rows;i++)
    {
        dp[i][0] = dp[i-1][0] + arr[i][0];
    }    
    for(int i=1;i<cols;i++)
    {
        dp[0][i] = dp[0][i-1] + arr[0][i];
    }

    for(int i=1;i<rows;i++)
    {
        for(int j=1;j<cols;j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1])+arr[i][j];
        }
    }

    return dp[rows-1][cols-1];

}

};