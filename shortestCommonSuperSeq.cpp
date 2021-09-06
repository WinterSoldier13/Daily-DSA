#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>
#define MOD 1000000007
#define object Solution ob

int dynamic(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();

    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

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

    return dp[l1][l2];
}

int shortestCommonSupersequence(char *X, char *Y, int m, int n)
{
    string s1;
    string s2;

    for (int i = 0; i < m; i++)
        s1 += X[i];
    for (int i = 0; i < n; i++)
        s2 += Y[i];


    int common = dynamic(s1, s2);

    return m+n-common;
}

int main()
{
    fast_cin();

    int n;
    cin >> n;

    object;
    cout << ob.nthPoint(n) << endl;
    return 0;
}
