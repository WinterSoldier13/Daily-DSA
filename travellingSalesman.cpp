#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int total_cost(vector<vector<int>> cost)
    {
        int Visited = (1 << cost.size()) - 1;
        vector<vector<int>> dp(pow(2, cost.size()), vector<int>(cost.size(), -1));
        int minCost = tsp(1, 0, cost, Visited, dp);
        return minCost;
    }

    int tsp(int mask, int pos, vector<vector<int>> &cost, int Visited, vector<vector<int>> &dp)
    {
        if (mask == Visited)
            return cost[pos][0];

        if (dp[mask][pos] != -1)
            return dp[mask][pos];
        int ans = INT_MAX;
        for (int i = 0; i < cost.size(); i++)
        {
            if ((mask & (1 << i)) == 0)
            {
                int temp = cost[pos][i] + tsp(mask | (1 << i), i, cost, Visited, dp);
                ans = min(ans, temp);
            }
        }
        return dp[mask][pos] = ans;
    }
};

int main()
{

    return 0;
}