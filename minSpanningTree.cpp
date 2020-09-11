#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V, int E, vector<vector<int>> &graph)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> dist(V, INT16_MAX);
    vector<int> visited(V, 0);

    dist[0] = 0;
    minHeap.push({0, 0});

    int count = 0;

    while (!minHeap.empty())
    {
        auto curr = minHeap.top();
        minHeap.pop();

        int currNode = curr.second;

        if(!visited[currNode])
        {
            visited[currNode] = 1;

            count+=dist[currNode];

            for(int i=0;i<V;i++)
            {
                if(!visited[i] and graph[currNode][i]!=INT_MAX)
                {
                    dist[i] = graph[currNode][i];
                    minHeap.push({dist[i], i});
                }
            }
        }
    }
    return count;
}
