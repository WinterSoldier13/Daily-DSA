#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool detectCycle(vector<vector<int>> &arr, int index, vector<int> &tracker, vector<int> &recursionStack)
{
    if(tracker[index] == 0)
    {
        tracker[index] = 1;
        recursionStack[index] = 1;

        for(int nodes: arr[index])
        {
            if(tracker[nodes] == 0 and detectCycle(arr, nodes, tracker, recursionStack))
            {
                return true;
            }
            else if(recursionStack[nodes] == 1)
            {
                return true;
            }
        }
    }
    recursionStack[index] = 0;
    return false;

}

bool dfs(vector<vector<int>> &arr, int n)
{
    vector<int> tracker(n,0);
    vector<int> recursionStack(n, 0);

    for(int i =0;i<n;i++)
    {
        if (detectCycle(arr, i, tracker, recursionStack))
        {
            return true;
        }
    }
    return false;
}


int main()
{
    vector<vector<int>> mat{{0,1},{0,2}, {1,2}};
    int n =3;
    vector<int> temp;
    vector<vector<int>> arr(n,temp);

    for(auto x: mat)
    {
        arr[x[0]].push_back(x[1]);
    }
    for(auto x: arr)
    {
        for(int c: x)
        {
            cout<<c<<" ";
        }
        cout<<endl;
    }

    cout<<!dfs(arr, n)<<endl;
    
}