#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

int bfs(vector<vector<int>> &graph)
{
    unordered_set<int> red;
    unordered_set<int> blue;
    queue<int> q;
    unordered_set<int> track;

    q.push(0);
    red.insert(0);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        track.insert(curr);

        int currentNodeColor;
        // Zero is blue 1 is red
        if (blue.count(curr))
        {
            currentNodeColor = 0;
        }
        else
        {
            currentNodeColor = 1;
        }

        for (auto node : graph[curr])
        {
            if (!track.count(node))
            {
                int thisNodeColor;
                if (currentNodeColor)
                {
                    thisNodeColor = 0;
                }
                else
                {
                    thisNodeColor = 1;
                }

                if (thisNodeColor == 1 and blue.count(node))
                {
                    return 0;
                }
                if (thisNodeColor == 0 and red.count(node))
                {
                    return 0;
                }

                if (thisNodeColor)
                {
                    red.insert(node);
                }
                else
                {
                    blue.insert(node);
                }

                q.push(node);
            }
        }
    }
    cout << "BLue ";
    for (auto it = blue.begin(); it != blue.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Red ";
    for (auto it = red.begin(); it != red.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 1;
}

bool isBipartite(vector<vector<int>> &arr)
{
    vector<vector<int>> graph(100);
    for (auto x : arr)
    {
        int l = x.size();

        for (int i = 0; i < l - 1; i++)
        {
            graph[x[i]].push_back(x[i + 1]);
        }
    }
    int count = 0;
    for (auto x : graph)
    {
        if (x.size() > 0)
        {
            cout << count++ << " || ";

            for (auto c : x)
            {
                cout << c << " ";
            }
            cout << endl;
        }
    }

    return bfs(graph);
}

int main()
{
    vector<vector<int>> graph{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << isBipartite(graph) << endl;
}