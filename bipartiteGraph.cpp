#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define tiii tuple<int, int, int>
#define MAX 500

bool isBipartite(int graph[][MAX], int V)
{

    for (int i = 0; i < V; i++)
    {
        unordered_set<int> redColor;
        unordered_set<int> blueColor;

        queue<int> q;
        unordered_set<int> tracker;
        q.push(i);
        tracker.insert(i);
        redColor.insert(i);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            int isRed = redColor.count(curr);

            for (int node = 0; node < MAX; node++)
            {
                if (graph[curr][node] == 0)
                {
                    continue;
                }
                if (tracker.count(node) == 0)
                {
                    if (isRed)
                    {
                        blueColor.insert(node);
                    }
                    else
                    {
                        redColor.insert(node);
                    }

                    tracker.insert(node);
                    q.push(node);
                }
                else
                {
                    int nodeColor = redColor.count(node);

                    if (nodeColor and isRed)
                    {
                        return 0;
                    }
                    if (!nodeColor and !isRed)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}