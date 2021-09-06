#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void recurse(vector<vector<int>> &arr, int index, vector<int> &track, stack<int> &stack)
{
    track[index] = 1;
    for(int nodes: arr[index])
    {
        if(track[nodes] == 0)
        {
            recurse(arr, nodes, track, stack);
        }
    }
    stack.push(index);
}

void dfs(vector<vector<int>> &arr, int n)
{
    stack<int> stack;
    vector<int> track(n,0);

    for(int i=0;i<n;i++)
    {
        if(track[i]==0)
        recurse(arr, i, track, stack);
    }

    while(!stack.empty())
    {
        cout<<stack.top()<<endl;
        stack.pop();
    }
}

int main()
{
    vector<vector<int>> mat{{1,0},{0,1}};
    int n =2;
    vector<int> temp;
    vector<vector<int>> arr(n,temp);

    for(auto x: mat)
    {
        arr[x[0]].push_back(x[1]);
    }

    dfs(arr, n);
    
}