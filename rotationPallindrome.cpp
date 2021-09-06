#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli long long int
// #define pii pair<int, int>
#define endl '\n'
#define printArr(arr)     \
    for (auto x : arr)    \
        cout << x << " "; \
    cout << endl;
#define printHashmap(hashmap)                                  \
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) \
    {                                                          \
        cout << it->first << " " << it->second << endl;        \
    }
#define print2DArray(arr)     \
    for (auto x : arr)        \
    {                         \
        for (auto c : x)      \
            cout << c << " "; \
        cout << endl;         \
    }

// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________
int expandFromMiddle(string &s, int l, int r)
{
    if (s == "" or l > r)
        return 0;

    while (l >= 0 and r < s.size() and s[l] == s[r])
    {
        l--;
        r++;
    }
    return r - l - 1;
}

int longestPalindrome(string s)
{
    int start = 0;
    int end = 0;

    if (s.size() <= 1)
    {
        return s.size();
    }

    for (int i = 0; i < s.size(); i++)
    {
        int len1 = expandFromMiddle(s, i, i);
        int len2 = expandFromMiddle(s, i, i + 1);

        int len = max(len1, len2);

        if (len > end - start + 1)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    return s.substr(start, end - start + 1).size();
}

int solve(string s)
{
    int l = s.size();
    if (l == 0 or l == 1)
        return l;

    string str = s + s;
    int ans = 0;
    for(int i=1;i<=l-1;i++)
    {
        string subString = str.substr(i,l);
        cout<<subString<<endl;
        ans = max(ans, longestPalindrome(subString));
    }
    return ans;
}

int main()
{
    fast_cin();
    string s = "oo";

    cout<<solve(s)<<endl;
    return 0;
}
