#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define piii pair<lli, pair<lli, lli>>

int dijstra(vector<vector<lli>> &graph)
{
    lli n = graph.size();
    vector<vector<lli>> dist(n, vector<lli>(n, INT_MAX));
    vector<vector<lli>> traveled(n, vector<lli>(n, 0));

    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, 1, 0, -1};

    priority_queue<piii, vector<piii>, greater<piii>> minHeap;
    dist[0][0] = graph[0][0];

    minHeap.push(make_pair(dist[0][0], make_pair(0, 0)));

    while (!minHeap.empty())
    {
        auto curr = minHeap.top();
        lli currDist = curr.first;
        auto currX = curr.second.first;
        auto currY = curr.second.second;

        minHeap.pop();

        if (traveled[currX][currY] == 0)
        {
            traveled[currX][currY] = 1;

            // No see it's neighbours
            for (lli i = 0; i < 4; i++)
            {
                auto newX = currX + dx[i];
                auto newY = currY + dy[i];

                if (newX < 0 or newX >= n or newY < 0 or newY >= n or traveled[newX][newY] == 1)
                {
                    continue;
                }
                else
                {
                    if (dist[newX][newY] > currDist + graph[newX][newY])
                    {
                        dist[newX][newY] = currDist + graph[newX][newY];
                        minHeap.push(make_pair(dist[newX][newY], make_pair(newX, newY)));
                    }
                }
            }
        }
    }
    // for(auto x: dist)
    // {
    //     for(auto c:x)
    //     {
    //         cout<<c<<" ";
    //     }
    //     cout<<endl;
    // }
    return dist[n - 1][n - 1];
}

int main()
{
    //code
    fast_cin();
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<lli>> arr(n, vector<lli>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        cout << dijstra(arr) << endl;
    }
    return 0;
}
