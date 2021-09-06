#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    bool isCycle;
    void detectCycleUtil(vector<vector<int>> &graph, int index, vector<int> &track, vector<int> &recursionStack)
    {
        track[index] = 1;
        if (recursionStack[index] == 1)
        {
            isCycle = true;
            return;
        }
        recursionStack[index] = 1;

        for(auto node : graph[index])
        {
            if(recursionStack[node])
            {
                isCycle = true;
                return;
            }
            if(track[node] == 0)
            {
                detectCycleUtil(graph, node, track, recursionStack);
            }
        }
        recursionStack[index] = 0;
    }

    bool detectCycle(vector<vector<int>> &graph, int n)
    {
        vector<int> tracker(n, 0);

        for (int i = 0; i < n; i++)
        {
            vector<int> recursionStack(n, 0);
            if (tracker[i] == 0)
            {
                detectCycleUtil(graph, i, tracker, recursionStack);
            }
        }
        return isCycle;
    }

    vector<vector<int>> makeGraph(int n, vector<vector<int>> &mat)
    {
        vector<int> temp;
        vector<vector<int>> arr(n, temp);

        for (auto x : mat)
        {
            arr[x[0]].push_back(x[1]);
        }
        return arr;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        isCycle = false;
        vector<vector<int>> graph = makeGraph(numCourses, prerequisites);
        return !detectCycle(graph, numCourses);

    }
};