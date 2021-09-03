#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

void dfs(vector<vector<char>> &arr, int i, int j)
{
    if (i < 0 or i >= arr.size() or j < 0 or j >= arr[0].size() or arr[i][j] != 'X')
    {
        return;
    }
    arr[i][j] = 'A';
    dfs(arr, i - 1, j);
    dfs(arr, i, j + 1);
    dfs(arr, i + 1, j);
    dfs(arr, i, j - 1);
}

int totalShapes(vector<vector<char>> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();

    int count = 0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(arr[i][j] == 'X')
            {
                count++;
                dfs(arr, i, j);
            }
        }
    }
    return count;
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

        vector<vector<char>> arr(rows, vector<char>(cols));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout<<totalShapes(arr)<<endl;
    }

    //code
    return 0;
}