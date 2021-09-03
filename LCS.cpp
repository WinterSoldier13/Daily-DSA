class Solution {
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int l1 = s1.size();
        int l2 = s2.size();
        
//         Handle base cases
        
        vector<int> t(l2+1,-1);
        vector<vector<int>> dp(l1+1, t);
        
        for(int i=0;i<=l1;i++)
            dp[i][0] = 0;
        for(int i=0;i<=l2;i++)
            dp[0][i] = 0;
        
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[l1][l2];
        
    }
};