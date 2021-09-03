class Solution{

	public:

int minCoins(int coins[], int M, int V)
{
    vector<int> dp(V + 1, INT32_MAX);
    dp[0] = 0;

    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (coins[j] <= i)
            {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT32_MAX and sub_res + 1 < dp[i])
                {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }
    return dp[V]==INT32_MAX?-1:dp[V];
}
	  
};