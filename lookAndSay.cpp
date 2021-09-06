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

#define pii pair<int, char>

string getBroken(string n)
{
    vector<pii> temp;
    string nString = n;
    int l = nString.size();

    int ptr = 0;

    while (ptr < l)
    {
        int count = 0;
        int ptr2 = ptr;

        while (ptr2 < l and nString[ptr2] == nString[ptr])
        {
            count++;
            ptr2++;
        }
        temp.push_back({count, nString[ptr]});
        ptr = ptr2;
    }

    string res = "";
    for (auto x : temp)
    {
        res.append(to_string(x.first));
        res.push_back(x.second);
    }
    return res;
}

string solve(int n)
{
    vector<string> dp;
    dp.push_back("1");
    dp.push_back("11");

    if (n - 1 == 0 or n - 1 == 1)
    {
        return (dp[n - 1]);
    }

    for (int i = 2; i < n; i++)
    {
        string prev = dp[i - 1];
        string newAns = getBroken(prev);
        dp.push_back(newAns);
    }
    return (dp[dp.size() - 1]);
}

int main()
{
    // fast_cin();
    getT()
    {
        int n;
        cin>>n;
        cout << solve(n) << endl;
    }
    return 0;
}
