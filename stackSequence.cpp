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
#define pii pair<int, int>
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

bool solve(vector<int> &pushes, vector<int> &pops)
{
    stack<int> s;
    int ptr1 = 0;
    int l = pushes.size();
    int ptr2 = 0;
    while (ptr2 < l)
    {
        s.push(pushes[ptr2++]);
        int temp;
        while (!s.empty() and s.top() == pops[ptr1])
        {
            ptr1++;
            s.pop();
        }
    }
    return s.empty();
}

int main()
{
    fast_cin();

    vector<int> pushes{1, 2, 3, 4};
    vector<int> pops{4, 1, 2, 3};

    cout << solve(pushes, pops) << endl;
    return 0;
}