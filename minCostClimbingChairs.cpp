class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int l = cost.size();
        if(l == 0)
        {
            return 0;
        }
        if(l == 1)
        {
            return cost[0];
        }

        vector<int> dp(l, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i  =2;i<l;i++)
        {
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        return min(dp[l-1], dp[l-2]);
        
    }
};