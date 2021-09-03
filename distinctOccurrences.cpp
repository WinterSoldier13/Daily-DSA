#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> mem;

    void __init__()
    {
        mem = vector<vector<int>>(8001, vector<int>(101, -1));
    }

public:
    int recurse(string s, int i, string t, int j)
    {
        if (mem[i][j] != -1)
        {
            return mem[i][j];
        }
        if (j == 0)
        {
            return mem[i][j] = 1;
        }
        if (i == 0)
        {
            return mem[i][j] = 0;
        }

        if (s[i - 1] == s[j - 1])
        {
            return mem[i][j] = recurse(s, i - 1, t, j - 1) + recurse(s, i - 1, t, j);
        }
        else
        {
            return mem[i][j] = recurse(s, i - 1, t, j);
        }
    }

    int dynamic(string s, string t)
    {
        int l1 = s.size();
        int l2 = t.size();

        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        for (int i = 0; i <= l1; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= l2; i++)
        {
            dp[0][i] = 1;
        }
        dp[0][0] = 1;
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                if (s[l1 - i] == t[l2-j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[l1][l2];
    }
    int subsequenceCount(string S, string T)
    {
        __init__();
        return dynamic(S, T);
        return recurse(S, S.size(), T, T.size());
    }
};

int main()
{
    string s = "geeksforgeeks";
    string t = "ge";

    Solution ob;
    cout << ob.subsequenceCount(s, t) << endl;
    return 0;
}