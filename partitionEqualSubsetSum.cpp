class Solution {
public:
        int dynamic(vector<int> arr)
    {
        int totalSum=0;
        int l = arr.size();
        
        for(int i=0;i<l;i++)
        {
            totalSum += arr[i];
        }
        if(totalSum%2!=0)
        {
            return 0;
        }
        
        int s = totalSum/2;
        
        vector<int> t(s+1);
        vector<vector<int>> dp(l+1, t);
        
        for(int i=0;i<=s;i++)
        {
            dp[0][i] = 0;
        }
        for(int i=0;i<=l;i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=l;i++)
        {
            for(int j=1;j<=s;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[l][s];
    }
    bool canPartition(vector<int>& nums) {
        return dynamic(nums);
        
    }
};