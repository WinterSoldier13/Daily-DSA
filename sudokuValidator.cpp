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

#define n 9


bool isSafe(vector<vector<int>> &arr, int i, int j)
{
    if(arr[i][j] <1 or arr[i][j]>9)
        return 0;
    int curr = arr[i][j];
    // check the col
    for(int k=0;k<n;k++)
    {
        if(k == i) continue;
        if(arr[k][j] == curr) return 0;
    }
    // check the row
    for(int k=0;k<n;k++)
    {
        if(k == j) continue;
        if(arr[i][k] == curr) return 0;
    }

    // check the 3x3 subgrid
    int x = i-i%3;
    int y = j-j%3;
    for(int alpha=0;alpha<3;alpha++)
    {
        for(int beta=0;beta<3;beta++)
        {
            int cX = x+alpha;
            int cY = y+beta;

            if(cX == i and cY == j) continue;
            if(arr[cX][cY] == curr) return 0;
        }
    }


    return 1;
}

bool solve(vector<vector<int>> &arr)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!isSafe(arr, i, j))
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    fast_cin();

    vector<vector<int>> arr{{1, 1}, {1, 0}};

    solve(arr);
    return 0;
}
