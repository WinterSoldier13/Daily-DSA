#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
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

    bool dfsDetect(vector<vector<int>> &arr, int n)
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
    
    vector<int> dfs(vector<vector<int>> &arr, int n)
    {
        vector<int> track(n,0);
        stack<int> stack;
        
        for(int i=0;i<n;i++)
        {
            if(track[i] == 0)
            {
                recurse(arr, i, track, stack);
            }
        }
        vector<int> out;
        while(!stack.empty())
        {
            out.push_back(stack.top());
            cout<<stack.top()<<endl;
            stack.pop();
        }
        reverse(out.begin(), out.end());
        return out;
    }
    
    
    vector<int> findOrder(int n, vector<vector<int>>& mat) 
    {
        vector<int> temp;
        vector<vector<int>> arr(n,temp);

        for(auto x: mat)
        {
            arr[x[0]].push_back(x[1]);
        }
        if(dfsDetect(arr, n))
        {
            return temp;
        }
        
        return dfs(arr, n);
    }
};