#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Leetcode 547 Friend Circle

class Solution
{
public:
    void recurseDFS(vector<vector<int>> &arr, int row, vector<int> &tracked)
    {
        int n = arr.size();

        for (int col = 0; col < n; col++)
        {
            int curr = arr[row][col];
            if (curr == 1 and tracked[col] == 0)
            {
                tracked[col] = 1;
                recurseDFS(arr, col, tracked);
            }
            else
            {
                continue;
            }
        }
    }

    int dfs(vector<vector<int>> &arr)
    {
        int count = 0;

        int n = arr.size();
        vector<int> tracked(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (tracked[i] == 0)
            {
                count++;
                tracked[i] = 1;
                recurseDFS(arr, i, tracked);
            }
        }
        return count;
    }

    void bfs(vector<vector<int>> &arr, vector<int> &tracker, int row)
    {
        queue<int> q;
        q.push(row);
        int n = arr.size();
        tracker[row] = 1;
        while (!q.empty())
        {
            int currentRow = q.front();
            q.pop();

            for (int i = 0; i < n; i++)
            {
                if (arr[currentRow][i] == 1 and tracker[i] == 0)
                {
                    tracker[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    int bfsLoop(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<int> tracker(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (tracker[i] == 0)
            {
                tracker[i] = 1;
                count++;
                bfs(arr, tracker, i);
            }
        }
        return count;
    }
    int findCircleNum(vector<vector<int>> &arr)
    {
        return dfs(arr);
        return bfsLoop(arr);
    }
};