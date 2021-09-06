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

int getLeftMostIndex(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = INT_MAX;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == 1)
        {
            end = mid - 1;
            ans = mid;
        }
        else
            start = mid + 1;
    }

    return ans;
}

int solve(vector<vector<int>> &arr)
{
    int rows = arr.size();
    if(rows ==0 )return -1;
    int cols = arr[0].size();

    int ans = INT_MAX;

    for (auto x : arr)
    {
        ans = min(ans, getLeftMostIndex(x));
    }
    return ans == INT_MAX? -1:ans;
}

int main()
{
    fast_cin();

    vector<vector<int>> arr{{0, 0, 0, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {0, 1, 1, 1}};

    cout << solve(arr) << endl;
    return 0;
}