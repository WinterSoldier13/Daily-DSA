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

void recurse(vector<vector<int>> &arr, int i, int j, int currIslandNumber, int &currLength)
{
    int rows = arr.size();
    int cols = arr[0].size();

    if (i < 0 or i >= rows or j < 0 or j >= cols or arr[i][j] != 1)
    {
        return;
    }
    currLength++;
    arr[i][j] = currIslandNumber;

    recurse(arr, i - 1, j, currIslandNumber, currLength);
    recurse(arr, i + 1, j, currIslandNumber, currLength);
    recurse(arr, i, j - 1, currIslandNumber, currLength);
    recurse(arr, i, j + 1, currIslandNumber, currLength);
}

unordered_map<int, int> markDifferentLandMasses(vector<vector<int>> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();

    int currIslandNumber = 101;
    unordered_map<int, int> hashmap;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 1)
            {
                int c = 0;
                recurse(arr, i, j, currIslandNumber, c);
                hashmap[currIslandNumber++] = c;
            }
        }
    }

    print2DArray(arr);
    printHashmap(hashmap);

    return hashmap;
}

int solve(vector<vector<int>> &arr)
{
    int rows = arr.size();
    if (rows == 0)
        return 0;
    int cols = arr[0].size();

    auto hashmap = markDifferentLandMasses(arr);
    int ans = 0;
    for (auto it = hashmap.begin(); it != hashmap.end(); it++)
    {
        ans = max(ans, it->second);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 0)
            {
                int up = 0;
                int down = 0;
                int right = 0;
                int left = 0;
                unordered_set<int> hashset;

                if (i - 1 >= 0 and !hashset.count(arr[i - 1][j]))
                {
                    up = arr[i - 1][j] == 0 ? 0 : hashmap[arr[i - 1][j]];
                    hashset.insert(arr[i - 1][j]);
                }
                if (i + 1 < rows and !hashset.count(arr[i + 1][j]))
                {
                    down = arr[i + 1][j] == 0 ? 0 : hashmap[arr[i + 1][j]];
                    hashset.insert(arr[i + 1][j]);
                }
                if (j - 1 >= 0 and !hashset.count(arr[i][j - 1]))
                {
                    left = arr[i][j - 1] == 0 ? 0 : hashmap[arr[i][j - 1]];
                    hashset.insert(arr[i][j - 1]);
                }
                if (j + 1 < cols and !hashset.count(arr[i][j + 1]))
                {
                    right = arr[i][j + 1] == 0 ? 0 : hashmap[arr[i][j + 1]];
                    hashset.insert(arr[i][j + 1]);
                }
                ans = max(ans, left + right + up + down + 1);
            }
        }
    }
    cout << ans << endl;
    return ans;
}

int main()
{
    fast_cin();

    vector<vector<int>> arr{{1, 1}, {1, 0}};

    solve(arr);
    return 0;
}
