#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

int isSafe(vector<vector<int>> &graph, vector<int> &colorOf, int node, int color)
{
    for (auto nodes : graph[node])
    {
        if (colorOf[nodes] == color)
        {
            return 0;
        }
    }
    return 1;
}

bool isAllColored(vector<int> &colorOf)
{
    for(auto x: colorOf)
    {
        if(x == -1)
        {
            return false;
        }
    }
    return 1;
}

void recurse(vector<vector<int>> &graph, int currNode, vector<int> &availableColors, vector<int> &colorOf)
{

    for (auto color : availableColors)
    {
        if (isSafe(graph, colorOf, currNode, color))
        {
            colorOf[currNode] = color;

            for (auto x : graph[currNode])
            {
                if (colorOf[x] == -1)
                     recurse(graph, x, availableColors, colorOf);
            }
        }
    }
}

int bfs(vector<vector<int>> &graph, int m)
{
    int n = graph.size();
    vector<int> colorOf(n, -1);
    vector<int> availableColors;
    for (int i = 0; i < m; i++)
    {
        availableColors.push_back(i);
    }

    for(int i=0;i<n;i++)
    {
        recurse(graph, i, availableColors, colorOf);
    }

    return isAllColored(colorOf);
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        int e;
        cin >> e;
        vector<vector<int>> graph(n, vector<int>(0));
        for (int i = 0; i < e; i++)
        {
            int u;
            int v;
            cin >> u >> v;
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
        cout << bfs(graph, m) << endl;
    }
    return 0;
}