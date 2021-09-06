#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli long long int
// #define pii pair<int, int>
#define endl '\n'
#define printArr(arr)     \
    for (auto x : arr)    \
        cout << x << " "; \
    cout << endl;
#define printHashmap(hashmap)                                  \
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) \
    {                                                          \
        cout << it->first << " " << it->second << endl;        \
    }
#define print2DArray(arr)     \
    for (auto x : arr)        \
    {                         \
        for (auto c : x)      \
            cout << c << " "; \
        cout << endl;         \
    }

// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________

class Solution
{
private:
    vector<vector<int>> generateGraph(vector<vector<int>> &arr)
    {
        int rows = arr.size();
        int cols = arr[0].size();

        int totalNodes = rows * cols;

        vector<vector<int>> graph(totalNodes, vector<int>(totalNodes, 0));
        vector<vector<int>> nodeMap(rows, vector<int>(cols, 0));

        int currNode = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                nodeMap[i][j] = currNode++;
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                currNode = nodeMap[i][j];
                int nextNode;
                if (i + 1 < rows)
                {
                    nextNode = nodeMap[i + 1][j];
                    graph[currNode][nextNode] = abs(arr[i][j] - arr[i + 1][j]);
                }
                if (i - 1 >= 0)
                {
                    nextNode = nodeMap[i - 1][j];
                    graph[currNode][nextNode] = abs(arr[i][j] - arr[i - 1][j]);
                }
                if (j - 1 >= 0)
                {
                    nextNode = nodeMap[i][j - 1];
                    graph[currNode][nextNode] = abs(arr[i][j] - arr[i][j - 1]);
                }
                if (j + 1 < cols)
                {
                    nextNode = nodeMap[i][j + 1];
                    graph[currNode][nextNode] = abs(arr[i][j] - arr[i][j + 1]);
                }
            }
        }

        return graph;
    }

    int dijstra(vector<vector<int>> &graph, int startNode, int endNode)
    {
        int n = graph.size();
        priority_queue<pair<int, int>> pq;
        vector<int> distance(n, INT_MAX);
        vector<int> processed(n, 0);
        distance[startNode] = 0;
        pq.push({0, startNode});

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            if (processed[curr.second])
                continue;
            processed[curr.second] = 1;

            for (int i = 0; i < n; i++)
            {
                if (graph[curr.second][i] == 0)
                    continue;

                int wgt = graph[curr.second][i];

                if (distance[curr.second] + wgt < distance[i])
                {
                    distance[i] = distance[curr.second] + wgt;
                    pq.push({-distance[i], i});
                }
            }
        }

        return distance[endNode];
    }

    int testRun(vector<vector<int>> &arr)
    {
        int rows = arr.size();
        int cols = arr[0].size();

        vector<vector<int>> distance(rows, vector<int>(cols, INT32_MAX));
        vector<vector<int>> processed(rows, vector<int>(cols, 0));

        priority_queue<pair<int, pair<int, int>>> pq;

        distance[0][0] = 0;
        // processed[0][0] = 1;
        pq.push({0, {0, 0}});

        vector<int> dx{-1, 0, 1, 0};
        vector<int> dy{0, 1, 0, -1};

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int currX = curr.second.first;
            int currY = curr.second.second;
            int currDis = curr.first;

            if (processed[currX][currY])
                continue;
            processed[currX][currY] = 1;

            for (int i = 0; i < 4; i++)
            {
                int nextNodeX = currX + dx[i];
                int nextNodeY = currY + dy[i];

                if (nextNodeX < rows and nextNodeX >= 0 and nextNodeY < cols and nextNodeY >= 0)
                {
                    int wgt = abs(arr[nextNodeX][nextNodeY] - arr[currX][currY]);

                    if (distance[nextNodeX][nextNodeY] > distance[currX][currY] + wgt)
                    {
                        distance[nextNodeX][nextNodeY] = distance[currX][currY] + wgt;
                        pq.push({-distance[nextNodeX][nextNodeY], {nextNodeX, nextNodeY}});
                    }
                }
                else
                    continue;
            }
        }
        return distance[rows - 1][cols - 1];
    }

public:
    int solve(vector<vector<int>> &arr)
    {
        // auto graph = generateGraph(arr);

        // cout << "PRINTING GRAPH" << endl;
        // print2DArray(graph);

        // int startNode = 0;
        // int endNode = arr.size() * arr[0].size() - 1;

        // int ans = dijstra(graph, startNode, endNode);
        int ans = testRun(arr);
        return ans;
    }
};

int solve(vector<vector<int>> &arr)
{
    int rows = arr.size();
    if (rows == 0)
        return 0;
    int cols = arr[0].size();
    if ((rows == 1 and cols == 1))
        return 0;

    Solution ob;
    return ob.solve(arr);
}

int main()
{
    fast_cin();

    vector<vector<int>> arr{{1, 100, 1}, {2, 5, 3}, {1, 2, 3}};
    cout<<solve(arr)<<endl;

    return 0;
}
