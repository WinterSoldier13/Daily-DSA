// A Naive recursive C++ program to find minimum of coins
// to make a given change V
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mem;

    void __init__(int l1, int l2)
    {
        vector<int> t(l2, -1);
        vector<vector<int>> temp(l1, t);
        mem = temp;
    }

    int recursion(string s1, int i, string s2, int j)
    {
        if (mem[i][j] != -1)
            return mem[i][j];

        if (i == 0 or j == 0)
        {
            return mem[i][j] = 0;
        }
        if (s1[i - 1] == s2[j - 1])
        {
            return mem[i][j] = 1 + recursion(s1, i - 1, s2, j - 1);
        }
        else
        {
            return mem[i][j] = max(recursion(s1, i - 1, s2, j), recursion(s1, i, s2, j - 1));
        }
    }

    int dp(string s1, string s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();

        // NOW from the recursive we can see that two variables are changing p1 and p2
        // Hence our DP will be 2D

        int dp[l1 + 1][l2 + 1];

        //NOW init with the base cases here in the dp

        for (int i = 0; i <= l1; i++)
        {
            for (int j = 0; j <= l2; j++)
            {
                if (i == 0 or j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return (dp[l1][l2] == min(l1, l2));
    }

    bool isSubsequence(string s1, string s2)
    {

        int l1 = s1.size();
        int l2 = s2.size();

        if (l1 == 0 and l2 == 0)
            return 1;
        if (l1 == 0 and l2 != 0)
            return 1;
        if (l1 != 0 and l2 == 0)
            return 0;

        return dp(s1, s2);

        //         __init__(l1,l2);

        //         int commonSeqSize = recursion(s1, s1.size(), s2, s2.size());

        //         int l = min(l1, l2);

        //         return (l == commonSeqSize);
    }
};