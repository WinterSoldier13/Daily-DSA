#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

vector<int> dijkstra(vector<vector<int>> graph, int src, int V)
{
    priority_queue<pii, vector<pii>, greater<pii>> minHeap;
    vector<int> dist(V, INT_MAX);
    vector<int> track(V, 0);

    dist[src] = 0;
    minHeap.push(make_pair(0, src));

    while (!minHeap.empty())
    {
        auto currDist = minHeap.top().first;
        auto currentNode = minHeap.top().second;

        minHeap.pop();

        if (track[currentNode] == 0)
        {
            track[currentNode] = 1;

            for (int node = 0; node < V; node++)
            {
                if (graph[currentNode][node] == 0)
                {
                    continue;
                }
                if (track[node] == 0)
                {
                    if (dist[node] > currDist + graph[currentNode][node])
                    {
                        dist[node] = currDist + graph[currentNode][node];
                        minHeap.push(make_pair(dist[node], node));
                    }
                }
            }
        }
    }
    return dist;
}