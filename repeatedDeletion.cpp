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

string solve(string str)
{
    int l = str.size();
    if (l == 0 or l == 1)
        return str;

    stack<char> s;
    int ptr = 0;

    while (ptr < l)
    {
        if (s.empty())
        {
            s.push(str[ptr]);
            ptr++;
            continue;
        }
        else if (!s.empty() and str[ptr] == s.top())
        {
            while (str[ptr] == s.top())
            {
                ptr++;
            }
            s.pop();
        }
        else
        {
            s.push(str[ptr]);
            ptr++;
        }
    }
    string ans = "";

    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    fast_cin();

    string s = "abbbaac";
    cout << solve(s) << endl;
    return 0;
}
