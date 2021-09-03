#include <bits/stdc++.h>
using namespace std;
#define lli long long int

class Solution
{
public:
    vector<vector<int>> cache;

    void __init__()
    {
        cache = vector<vector<int>>(1001, vector<int>(1001, -1));
    }

    int recurse(string s, int i, string p, int j)
    {
        if (cache[i][j] != -1)
        {
            return cache[i][j] = cache[i][j];
        }
        if (i == 0)
        {
            return cache[i][j] = j;
        }
        if (j == 0)
        {
            return cache[i][j] = i;
        }

        if (s[i - 1] == p[j - 1])
        {
            return cache[i][j] = recurse(s, i - 1, p, j - 1);
        }
        else
        {
            return cache[i][j] = 1 + min(recurse(s, i - 1, p, j), recurse(s, i, p, j - 1));
        }
    }

    int dynamic(string s, string p)
    {
        int l1 = s.size();
        int l2 = p.size();

        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        for (int i = 0; i <= l2; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 0; i <= l1; i++)
        {
            dp[i][0] = i;
        }
        dp[0][0] = 0;
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                if (s[i - 1] == p[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[l1][l2];
    }
    int minOperations(string str1, string str2)
    {
        __init__();
        return recurse(str1, str1.size(), str2, str2.size());
    }
};

int main()
{
    Solution ob;
    string s = "geeksforgeeks";
    string p = "geeks";

    cout << ob.minOperations(s, p) << endl;
    cout << ob.dynamic(s, p) << endl;
    return 0;
}