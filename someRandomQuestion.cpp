#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int


void recurse(vector<vector<char>> &arr, int i, int j)
{
    int rows = arr.size();
    int cols = arr[0].size();

    if(i<0 or i>=rows or j<0 or j>=cols or arr[i][j] != 'X')
    {
        return;
    }
    arr[i][j] = 'O';

    recurse(arr, i-1, j);
    recurse(arr, i, j+1);
    recurse(arr, i+1, j);
    recurse(arr, i, j-1);

}

vector<vector<char>> convert2Arr(vector<string> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();

    vector<char> t(cols);
    vector<vector<char>> graph(rows, t);

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            graph[i][j] = arr[i][j];
        }
    }
    return graph;
}

int Shape(vector<string> &arr,int n,int m) 
{
    vector<vector<char>> graph = convert2Arr(arr);

    int rows = graph.size();
    int cols = graph[0].size();

    int count = 0;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(graph[i][j] == 'X')
            {
                count++;
                recurse(graph, i, j);
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

    return 1;
}