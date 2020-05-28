#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Leetcode 547 Friend Circle




void recurseDFS(vector<vector<int>> &arr, int row, vector<int> &tracked)
{
    int n = arr.size();

    for(int col =0;col<n;col++)
    {
        int curr = arr[row][col];
        if(curr==1 and tracked[col]==0)
        {
            tracked[col] = 1;
            recurseDFS(arr, col, tracked);
        }
        else
        {
            continue;
        }
        
    }

}


int dfs(vector<vector<int>> &arr)
{
    int count = 0;

    int n=arr.size();
    vector<int> tracked(n,0);

    for(int i=0;i<n;i++)
    {
        if(tracked[i]==0)
        {
            count++;
            tracked[i]=1;
            recurseDFS(arr, i, tracked);
        }

    }
    return count;

}


int findCircleNum(vector<vector<int>>& arr) 
{
    return dfs(arr);
}

int main()
{
    vector<vector<int>> graph{{1,0,0,1},
                                {0,1,1,0},
                                {0,1,1,1},
                                {1,0,1,1}};
    cout<<findCircleNum(graph)<<endl;
}