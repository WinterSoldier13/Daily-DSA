#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
private:
    vector<vector<int>> out;

    void recurse(vector<int> graph[], int V, int current, vector<int> &disc, vector<int> &low, vector<bool> &inStack, stack<int> &nodeStack, int &time)
    {
        disc[current] = low[current] = ++time;
        nodeStack.push(current);
        inStack[current] = true;

        for (auto node : graph[current])
        {
            if (disc[node] == -1)
            {
                recurse(graph, V, node, disc, low, inStack, nodeStack, time);

                low[current] = min(low[current], low[node]);
            }

            // if it is a backedge
            else if (inStack[node])
            {
                low[current] = min(low[current], disc[node]);
            }
        }

        vector<int> temp;

        if (low[current] == disc[current])
        {
            while (nodeStack.top() != current)
            {
                temp.push_back(nodeStack.top());
                inStack[nodeStack.top()] = false;
                nodeStack.pop();
            }
            temp.push_back(nodeStack.top());
            inStack[nodeStack.top()] = false;
            nodeStack.pop();
        }

        if (temp.size() != 0)
        {
            out.push_back(temp);
        }
    }
    void __init__()
    {
        out.clear();
    }

    void printOut()
    {
        for (auto x : out)
        {
            for (auto c : x)
            {
                cout << c << " ";
            }
            cout << endl;
        }
    }

public:
    vector<vector<int>> tarjans(int V, vector<int> graph[])
    {
        __init__();
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> nodeStack;
        int time = 0;
        for (int i = 0; i < V; i++)
        {
            if (disc[i] == -1)
            {
                recurse(graph, V, i, disc, low, inStack, nodeStack, time);
            }
        }
        printOut();
        return out;
    }
};

int main()
{
    fast_cin();
    int V, E;
    cin >> V >> E;

    vector<int> arr[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
    }

    Solution ob;

    ob.tarjans(V, arr);

    return 0;
}