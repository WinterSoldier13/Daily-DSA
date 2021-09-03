#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
public:
    /*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    void dfs1(vector<int> adj[], vector<bool> &vis, stack<int> &stk, int src)
    {
        vis[src] = true;
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                dfs1(adj, vis, stk, it);
            }
        }
        stk.push(src);
    }
    void dfs2(vector<int> rev[], vector<bool> &vis, int src)
    {
        vis[src] = true;
        for (auto it : rev[src])
        {
            if (!vis[it])
            {
                dfs2(rev, vis, it);
            }
        }
    }
    void reverse(vector<int> adj[], vector<int> rev[], int v)
    {
        for (int i = 0; i < v; i++)
        {
            for (auto j : adj[i])
            {
                rev[j].push_back(i);
            }
        }
    }
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> stk;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs1(adj, vis, stk, i);
            }
        }
        vector<int> rev[V];
        reverse(adj, rev, V);
        for (int i = 0; i < V; i++)
        {
            vis[i] = false;
        }
        int count = 0;
        while (!stk.empty())
        {
            int node = stk.top();
            stk.pop();
            if (!vis[node])
            {
                count++;
                dfs2(rev, vis, node);
            }
        }
        return count;
    }
};
int main()
{
    return 0;
}