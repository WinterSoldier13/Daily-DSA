#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>


void dfs(vector<vector<int>> &arr, int i, int j, pair<int, int> &dest, int &maxD, int currentD)
{
    int rows = arr.size();
    int cols = arr[0].size();

    if(i< 0 or i>=rows or j<0 or j>=cols or arr[i][j] != 1)
    {
        return;
    }
    if(i == dest.first and j == dest.second)
    {
        maxD = max(maxD, currentD);
    }
    arr[i][j] = -1;

    dfs(arr, i-1, j, dest, maxD, currentD+1);
    dfs(arr, i, j+1, dest, maxD, currentD+1);
    dfs(arr, i+1, j, dest, maxD, currentD+1);
    dfs(arr, i, j-1, dest, maxD, currentD+1);

    arr[i][j] = 1;
}

void solve(vector<vector<int>> &arr, pair<int, int> &source, pair<int, int> &dest)
{
    int maxD = -1;

    dfs(arr, source.first, source.second, dest, maxD, 0);
    cout<<maxD<<endl;
}


int main()
{
    fast_cin();
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> arr{
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    pair<int, int> source = make_pair(0, 0);
    pair<int, int> destination = make_pair(1, 7);

    solve(arr, source, destination);
}