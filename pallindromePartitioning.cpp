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

class Solution
{
private:
    bool isPallindrome(string s, int start, int end)
    {
        int i = start, j = end;

        while (start < end)
        {
            if (s[start] != s[end])
            {
                return 0;
            }
            start++;
            end--;
        }
        return 1;
    }

    vector<vector<int>> recurseCache;

public:
    Solution()
    {
        recurseCache = vector<vector<int>>(501, vector<int>(501, -1));
    }
    int recurse(string str, int start, int end)
    {
        if (recurseCache[start][end] != -1)
        {
            return recurseCache[start][end];
        }
        // cout<<"we recursiiiiiinnnnnnnggggg : "<<str.substr(start, end-start+1)<<endl;
        if (start >= end or isPallindrome(str, start, end))
        {
            return 0;
        }

        int result = INT16_MAX;

        for (int i = start; i < end; i++)
        {
            int ans = 1 + recurse(str, start, i) + recurse(str, i + 1, end);
            result = min(result, ans);
        }
        return recurseCache[start][end] = result;
    }

    int dynamic(string str)
    {
        
        int n = str.length();
        int C[n][n];
        bool P[n][n];

        for (int i = 0; i < n; i++)
        {
            P[i][i] = true;
            C[i][i] = 0;
        }

        for (int L = 2; L <= n; L++)
        {

            for (int i = 0; i < n - L + 1; i++)
            {
                int j = i + L - 1; // Set ending index

                // If L is 2, then we just need to
                // compare two characters. Else
                // need to check two corner characters
                // and value of P[i+1][j-1]
                if (L == 2)
                    P[i][j] = (str[i] == str[j]);
                else
                    P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];

                // IF str[i..j] is palindrome, then C[i][j] is 0
                if (P[i][j] == true)
                    C[i][j] = 0;
                else
                {

                    // Make a cut at every possible
                    // location starting from i to j,
                    // and get the minimum cost cut.
                    C[i][j] = INT_MAX;
                    for (int k = i; k <= j - 1; k++)
                        C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1);
                }
            }
        }

        // Return the min cut value for
        // complete string. i.e., str[0..n-1]
        return C[0][n - 1];
    }

    int palindromicPartition(string str)
    {
        return dynamic(str);
        return recurse(str, 0, str.size() - 1);
    }
};

int main()
{
    fast_cin();
    object;

    cout << ob.palindromicPartition("ababbbabbababa") << endl;

    // string s = "";
    // cout<<ob.isPallindrome(s, 0, s.size()-1)<<endl;

    // string str = "abcde";
    // int start = 0;
    // int end = str.size() - 1;
    // for (int i = start; i <= end + 1; i++)
    // {
    //     string part1 = str.substr(start, i);
    //     string part2 = str.substr(i);

    //     cout << part1 << " " << part2 << endl;
    // }
    return 0;
}
