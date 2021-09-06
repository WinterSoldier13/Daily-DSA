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



// IN CASE OF TLE 



// class Solution
// {
// public:
//     vector<int> p, rk;

//     int getp(int v)
//     {
//         if (v == p[v])
//             return v;
//         return p[v] = getp(p[v]);
//     }

//     long long res;

//     long long get(int cnt)
//     {
//         return cnt * 1ll * (cnt - 1) / 2;
//     }

//     void merge(int u, int v)
//     {
//         u = getp(u);
//         v = getp(v);

//         if (rk[u] < rk[v])
//             swap(u, v);

//         res -= get(rk[u]);
//         res -= get(rk[v]);

//         rk[u] += rk[v];

//         res += get(rk[u]);

//         p[v] = u;
//     }

//     vector<int> maximumWeight(int n, vector<vector<int>> edges, int m, vector<int> &queries)
//     {
//         res = 0;
//         p = rk = vector<int>(n, 1);
//         iota(p.begin(), p.end(), 0);
//         vector<pair<int, pair<int, int>>> e(n - 1);
//         for (int i = 0; i < n - 1; ++i)
//         {
//             e[i].second.first = edges[i][0];
//             e[i].second.second = edges[i][1];
//             e[i].first = edges[i][2];

//             --e[i].second.first;
//             --e[i].second.second;
//         }
//         vector<pair<int, int>> q(m);
//         vector<int> ans(m);

//         for (int i = 0; i < m; ++i)
//         {
//             q[i].first = queries[i];
//             q[i].second = i;
//         }
//         sort(e.begin(), e.end());
//         sort(q.begin(), q.end());
//         int pos = 0;
//         for (int i = 0; i < m; ++i)
//         {
//             while (pos < n - 1 && e[pos].first <= q[i].first)
//             {
//                 int u = e[pos].second.first;
//                 int v = e[pos].second.second;
//                 merge(u, v);
//                 ++pos;
//             }
//             ans[q[i].second] = res;
//         }

//         return ans;
//     }
// };



class Solution
{
private:
    vector<vector<int>> graph;
    map<int, int> hashmap;
    unordered_set<string> hashset;
    int N;

    void __init__(int n)
    {
        graph = vector<vector<int>>(n, vector<int>(n, 0));
        hashmap.clear();
        N = n;
    }

    void createGraph(int n, vector<vector<int>> &edges)
    {
        for (auto x : edges)
        {
            int u = x[0] - 1;
            int v = x[1] - 1;
            int w = x[2];

            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    void recurse(int current, int pathSize, vector<int> &visited, vector<int> &path)
    {
        if (pathSize != 0)
        {
            hashmap[*max_element(path.begin(), path.end())]++;
        }
        for (int i = 0; i < N; i++)
        {
            if (current == i)
            {
                continue;
            }

            if (graph[current][i] != 0)
            {
                if (visited[i] == 0)
                {
                    visited[i] = 1;
                    path.push_back(graph[current][i]);
                    recurse(i, pathSize + 1, visited, path);
                    path.pop_back();
                }
            }
        }
    }

    void dfs()
    {
        for (int i = 0; i < N; i++)
        {
            vector<int> track(N, 0);
            track[i] = 1;
            vector<int> path;
            recurse(i, 0, track, path);
        }
    }

    void printHashmap()
    {
        cout << endl
             << endl;

        for (auto it = hashmap.begin(); it != hashmap.end(); it++)
        {
            cout << it->first << " : " << it->second << endl;
        }
        cout << endl
             << endl;
    }

    void printGraph()
    {
        cout << endl
             << endl;
        for (int i = 0; i < N; i++)
        {
            auto x = graph[i];
            cout << i << " :  ";
            for (auto c : x)
            {
                cout << c << " ";
            }
            cout << endl;
        }
        cout << endl
             << endl;
    }

public:
    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
    {
        __init__(n);
        createGraph(n, edges);
        dfs();
        vector<int> out;
        for (int i = 0; i < q; i++)
        {
            int query = queries[i];
            int count = 0;
            for (auto it = hashmap.begin(); it != hashmap.end(); it++)
            {
                if (it->first <= query)
                {
                    count += it->second;
                }
                else
                {
                    break;
                }
                
            }
            out.push_back(count/2);
        }
        printGraph();
        printHashmap();
        return out;
    }
};

int main()
{
    fast_cin();

    vector<vector<int>> edges{{1, 2, 3}, {2, 3, 1}, {2, 4, 9}, {3, 6, 7}, {3, 5, 8}, {5, 7, 4}};
    int n = 7;
    int q = 3;
    vector<int> queries{1,3,5};
    Solution ob;

    auto ans = ob.maximumWeight(n, edges, q, queries);

    for (auto x : ans)
        cout << x << ' ';
    cout << endl;

    return 0;
}