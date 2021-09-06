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

struct customSort
{
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] < b[0])
            return 1;
        else if (a[0] == b[0])
            return a[1] > b[1];
        return 0;
    }
};

bool solve(vector<vector<int>> &trips, int capacity)
{
    int l = trips.size();
    sort(trips.begin(), trips.end(), customSort());

    print2DArray(trips);

    int count = 0;
    int ptr = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    while (ptr < l)
    {
        while (!minHeap.empty() and minHeap.top().first <= trips[ptr][0])
        {
            auto top = minHeap.top();
            minHeap.pop();

            count -= top.second;
        }

        count += trips[ptr][2];
        if (count > capacity)
            return false;
        minHeap.push({trips[ptr][1], trips[ptr][2]});
        ptr++;
    }

    return true;
}

int main()
{
    fast_cin();

    vector<vector<int>> arr{{0, 2, 3}, {1, 4, 3}, {2, 4, 1}, {3, 4, 1}};
    int cap = 7;

    cout << solve(arr, cap) << endl;
    return 0;
}