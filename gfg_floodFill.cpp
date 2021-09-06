#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

void recurse(vector<vector<int>> &arr, int i, int j, int oldColor, int color)
{
    if (i < 0 or i >= arr.size() or j < 0 or j >= arr[0].size() or arr[i][j] != oldColor)
    {
        return;
    }
    arr[i][j] = color;
    recurse(arr, i - 1, j, oldColor, color);
    recurse(arr, i, j + 1, oldColor, color);
    recurse(arr, i + 1, j, oldColor, color);
    recurse(arr, i, j - 1, oldColor, color);
}

void solve(vector<vector<int>> &arr, int x, int y, int color)
{
    int oldColor = arr[x][y];
    recurse(arr, x, y, oldColor, color);
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int rows, cols;
        cin >> rows >> cols;

        vector<vector<int>> arr(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> arr[i][j];
            }
        }
        int x, y, c;
        cin >> x >> y >> c;

        solve(arr, x, y, c);
        for (auto x : arr)
        {
            for (auto c : x)
            {
                cout << c << " ";
            }
        }
        cout << endl;
    }
    return 0;
}