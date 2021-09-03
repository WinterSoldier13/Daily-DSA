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
private:
    vector<vector<int>> mem;

    void __init__(int n, int m)
    {
        mem = vector<vector<int>>(n, vector<int>(m, -1));
    }
    int recurse(vector<vector<int>> &arr, int i, int j, int prevEle)
    {
        int rows = arr.size();
        int cols = arr[0].size();
        // cout<<i<<" "<<j<<endl;
        if (i < 0 or i >= rows or j < 0 or j >= cols or arr[i][j] <= prevEle)
        {
            return 0;
        }

        if (mem[i][j] != -1)
        {
            return mem[i][j];
        }

        vector<int> dx{-1, 0, 1, 0};
        vector<int> dy{0, 1, 0, -1};
        int ans = INT_MIN;
        for (int k = 0; k < 4; k++)
        {
            ans = max(ans, 1 + recurse(arr, i + dx[k], j + dy[k], arr[i][j]));
        }
        return mem[i][j] = ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>> &arr)
    {
        int ans = 1;
        int rows = arr.size();
        int cols = arr[0].size();
        __init__(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                ans = max(ans, recurse(arr, i, j, INT_MIN));
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> arr{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    Solution ob;
    cout << ob.longestIncreasingPath(arr) << endl;
    return 0;
}