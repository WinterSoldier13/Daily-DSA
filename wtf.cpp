#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tiii tuple<int, int, int>
// Leetcode 787
class Solution
{
public:
    int bfs(vector<vector<int>> &graph, int n, int src, int dst, int k)
    {
        vector<int> distance(n, INT32_MAX);
        vector<int> track(n, 0);

        //  cost,Node, stops
        priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
        pq.push({0, src, 0});
        distance[src] = 0;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int currentDist = get<0>(curr);
            int currentNode = get<1>(curr);
            int currentK = get<2>(curr);

            track[currentNode] = 1;

            if (currentK >= k + 1)
            {
                continue;
            }

            for (int i = 0; i < n; i++)
            {
                int dis = graph[currentNode][i];
                if (dis == 0)
                {
                    continue;
                }
                if (track[i] == 0)
                {
                    // cout << "Travelling to node number : " << i << endl;
                    if (distance[i] > currentDist + dis)
                    {
                        distance[i] = currentDist + dis;
                        pq.push({distance[i], i, currentK + 1});
                    }
                }
            }
        }

        if (distance[dst] == INT32_MAX)
        {
            return -1;
        }
        return distance[dst];
    }

    vector<vector<int>> makeGraph(int n, vector<vector<int>> &flights)
    {
        vector<vector<int>> graph(n, vector<int>(n, 0));

        for (auto x : flights)
        {
            graph[x[0]][x[1]] = x[2];
        }
        return graph;
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<int>> graph = makeGraph(n, flights);
        int ans = bfs(graph, n, src, dst, k);
        cout << ans << endl;

        return ans;
    }
};

int main()
{
    vector<vector<int>> edges{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};

    Solution ob;
    ob.findCheapestPrice(3, edges, 0, 2, 1);
}