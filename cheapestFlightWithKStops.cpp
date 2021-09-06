#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tiii tuple<int, int, int>

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &a, int src, int dest, int k)
    {

        vector<vector<pair<int, int>>> g;
        g.resize(n + 1);

        int INF = 1e9;
        int u, v, w;
        for (int i = 0; i < a.size(); i++)
        {
            u = a[i][0];
            v = a[i][1];
            w = a[i][2];

            g[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INF);
        priority_queue<tiii> pq; //cost , place , numOfEdges

        dist[src] = 0;
        pq.push({0, src, 0});

        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            u = get<1>(p);
            //This is the only change from a normal Djikstra
            if (get<2>(p) >= k + 1)
                continue; //It has already k stops in between source and itself
            //////////////////////

            for (auto q : g[u])
            {
                v = q.first;
                w = q.second;

                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v, get<2>(p) + 1});
                }
            }
        }

        if (dist[dest] - dist[src] == INF)
            return -1;
        return dist[dest] - dist[src];
    }
};