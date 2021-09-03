#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

class Solution
{
public:
    void makeGraph(vector<vector<int>> &graph, vector<vector<int>> &arr)
    {
        for (auto x : arr)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
    }

    void countOfDisconnectedCompnentsHelper(vector<vector<int>> &graph, int n, unordered_set<int> &track)
    {
        if (track.count(n))
        {
            return;
        }
        track.insert(n);

        for (auto node : graph[n])
        {
            if (track.count(node) == 0)
            {
                countOfDisconnectedCompnentsHelper(graph, node, track);
            }
        }
    }
    int countOfDisconnectedComponents(vector<vector<int>> &graph)
    {
        int n = graph.size();
        unordered_set<int> track;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (track.count(i) == 0)
            {
                count++;
                countOfDisconnectedCompnentsHelper(graph, i, track);
            }
        }
        return count;
    }

    void sizeOfFirstComponentHelper(vector<vector<int>> &graph, int n, unordered_set<int> &track, int &count)
    {
        if (track.count(n))
        {
            return;
        }
        track.insert(n);
        count++;
        for (auto node : graph[n])
        {
            if (track.count(node) == 0)
            {
                sizeOfFirstComponentHelper(graph, node, track, count);
            }
        }
    }

    int sizeOfFirstComponent(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int count = 0;
        int maxSize = 0;
        unordered_set<int> track;

        for (int i = 0; i < n; i++)
        {
            count = 0;
            if (track.count(i) == 0)
            {
                sizeOfFirstComponentHelper(graph, i, track, count);
                maxSize = max(maxSize, count);
            }
        }
        return maxSize;
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<int> t;
        vector<vector<int>> graph(n, t);
        
        int totalEdges = connections.size();
        if(totalEdges < n-1)
        {
            return -1;
        }

        makeGraph(graph, connections);
        int countOfDisconnected = countOfDisconnectedComponents(graph);
        int sizeOfBiggestComponent = sizeOfFirstComponent(graph);

        int numberOfCablesNeeded = countOfDisconnected - 1;
        
        return numberOfCablesNeeded;
    }
};

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> arr{{0, 1}, {0, 2}, {1, 2}};
    int n = 4;

    Solution ob;
    ob.makeConnected(n, arr);
    return 0;
}