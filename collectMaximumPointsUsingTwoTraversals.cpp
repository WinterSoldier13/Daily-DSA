#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define tiiii tuple<int, int, int, int>

map<tiiii, int> mem;

int isInvalid(vector<vector<int>> &arr, int x, int y)
{
    int rows = arr.size();
    int cols = arr[0].size();

    if (x < 0 or x >= rows or y < 0 or y >= cols)
    {
        return 1;
    }
    return 0;
}

int recurse(vector<vector<int>> &arr, int x1, int y1, int x2, int y2)
{
    int rows = arr.size();
    int cols = arr[0].size();

    if (isInvalid(arr, x1, y1) or isInvalid(arr, x2, y2))
    {
        return INT32_MIN;
    }
    if (x1 == rows - 1)
    {
        return INT32_MIN;
    }
    if (mem.find({x1, y1, x2, y2}) != mem.end())
    {
        return mem[{x1, y1, x2, y2}];
    }

    int ans = INT32_MIN;

    int temp = y1 == y2 ? arr[x1][y1] : arr[x1][y1] + arr[x2][y2];

    ans = max(ans, temp + recurse(arr, x1 + 1, y1, x2 + 1, y2 - 1));
    ans = max(ans, temp + recurse(arr, x1 + 1, y1, x2 + 1, y2 + 1));
    ans = max(ans, temp + recurse(arr, x1 + 1, y1, x2 + 1, y2));

    ans = max(ans, temp + recurse(arr, x1 + 1, y1 - 1, x2 + 1, y2));
    ans = max(ans, temp + recurse(arr, x1 + 1, y1 - 1, x2 + 1, y2 - 1));
    ans = max(ans, temp + recurse(arr, x1 + 1, y1 - 1, x2 + 1, y2 + 1));

    ans = max(ans, temp + recurse(arr, x1 + 1, y1 + 1, x2 + 1, y2));
    ans = max(ans, temp + recurse(arr, x1 + 1, y1 + 1, x2 + 1, y2 - 1));
    ans = max(ans, temp + recurse(arr, x1 + 1, y1 + 1, x2 + 1, y2 + 1));

    return mem[{x1, y1, x2, y2}] = ans;
}

void solve(vector<vector<int>> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();
    mem.clear();

    cout << recurse(arr, 0, 0, 0, cols - 1);
}

int main()
{
    vector<vector<int>> arr{{3, 6, 8, 2}, {5, 2, 4, 3}, {1, 1, 20, 10}, {1, 1, 20, 10}, {1, 1, 20, 10}};
}