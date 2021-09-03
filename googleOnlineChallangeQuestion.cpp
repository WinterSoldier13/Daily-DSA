#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int4

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int isCoprime(int a, int b)
{
    return __gcd(a,b)==1;
}
void bfs(vector<vector<int>> &graph, vector<int> &val, int index, vector<int> &out)
{
    queue<int> q;
    unordered_set<int> track;

    q.push(index);
    track.insert(index);
    int currVal = val[index];

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto node : graph[curr])
        {
            if (!track.count(node))
            {
                int nodeVal = val[node];

                if (isCoprime(currVal, nodeVal))
                {
                    out.push_back(node + 1);
                    return;
                }

                track.insert(node);
                q.push(node);
            }
        }
    }
    out.push_back(-1);
    return;
}

void myWay(vector<vector<int>> &graph, vector<int> &val, int n)
{
    vector<int> out;

    for (int i = 0; i < n; i++)
    {
        bfs(graph, val, i, out);
    }
    for (auto x : out)
    {
        cout << x << " ";
    }
    cout << endl;
}

void printGraph(vector<vector<int>> graph)
{
    int count = 1;
    for (auto x : graph)
    {
        cout << count++ << " || ";
        for (auto c : x)
        {
            cout << c + 1 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> val(n);
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        vector<int> t;
        vector<vector<int>> graph(n, t);

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            // graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
        printGraph(graph);
        myWay(graph, val, n);


    }
}
