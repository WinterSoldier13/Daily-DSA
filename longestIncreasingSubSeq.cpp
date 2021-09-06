class Solution
{
public:

    int dp(vector<int> arr)
    {
        int l = arr.size();
        vector<int> dp(l, 1);

        dp[0] = 1;

        for (int i = 1; i < l; i++)
        {
            int curr = arr[i];
            int maxL = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] < curr)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int maxEle = -1;
        for (auto x : dp)
            maxEle = max(maxEle, x);

        return maxEle;
    }

    int lengthOfLIS(vector<int> &arr)
    {
        if ((int)arr.size() == 0)
        {
            return 0;
        }
        return dp(arr);
    }
};