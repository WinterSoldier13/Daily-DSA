#include <bits/stdc++.h>
using namespace std;

void primsAlgo(vector<vector<int>> &graph)
{
    int v = graph.size();

    vector<int> parent(v, -1);   // at index i it specifies the parent of the ith node
    vector<bool> mst(v, false);  // it specifies whether the index has been already included in the mst
    vector<int> dis(v, INT_MAX); // it specifies the distance

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // insert the first node
    dis[0] = 0;
    parent[0] = -1;
    minHeap.push({0, 0});

    for (int count = 0; count < v; count++)
    {
        auto curr = minHeap.top();
        minHeap.pop();

        int currNode = curr.second;
        mst[currNode] = true;

        for (int node = 0; node < v; node++)
        {
            int wgt = graph[currNode][node];
            if (wgt == INT_MAX)
                continue;

            if (mst[node] == false and wgt < dis[node])
            {
                parent[node] = currNode;
                dis[node] = wgt;
                minHeap.push({dis[node], node});
            }
        }
    }

    // now the parent array contains all the information, i.e which child is the node of which child 
    // int the spanning tree
}

int main()
{
    vector<vector<int>> graph;
    primsAlgo(graph);
    return 0;
}