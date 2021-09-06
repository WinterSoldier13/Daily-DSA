#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

bool possible;

void recurse(vector<vector<int>> &arr, int i, int j)
{
    int cols;
    int rows = cols = arr.size();
    if (i < 0 or i >= rows or j < 0 or j >= cols or arr[i][j] == 0)
    {
        return;
    }
    if (arr[i][j] == 2)
    {
        possible = true;
        return;
    }
    int temp = arr[i][j];
    arr[i][j] = 0;

    recurse(arr, i, j + 1);
    recurse(arr, i, j - 1);
    recurse(arr, i + 1, j);
    recurse(arr, i - 1, j);
}

int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        pair<int, int> index;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j] == 1)
                {
                    index = {i,j};
                }
            }
        }
        possible = false;
        recurse(arr, index.first, index.second);
        cout<<possible<<endl;
    }
}