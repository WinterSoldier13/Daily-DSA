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

class Solution
{
public:
    int count;
    Solution()
    {
        count = 0;
    }

    void helperFunction(string s, int left, int right)
    {
        while (left >= 0 and right < s.size() and s[left] == s[right])
        {
            if (left != right)
            {
                count++;
            }
            left--;
            right++;
        }
    }

    void solve(string s)
    {
        int l = s.size();

        for (int i = 0; i < l; i++)
        {
            helperFunction(s, i, i);
            helperFunction(s, i, i + 1);
        }

        cout << count << endl;
    }
};

int main()
{
    fast_cin();

    getT()
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        Solution ob;
        ob.solve(s);
    }

    return 0;
}