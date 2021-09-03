#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
public:
    int bfs(vector<vector<int>> &arr, int i, int j)
    {
        queue<pii> q;
        int rows = arr.size();
        int cols = arr[0].size();

        vector<vector<int>> track(rows, vector<int>(cols, 0));

        q.push(make_pair(i, j));
        track[i][j] = 1;

        int res = 0;
        vector<int> dx{-1, 0, 1, 0};
        vector<int> dy{0, 1, 0, -1};

        if (arr[i][j] == 1)
        {
            return res;
        }

        while (!q.empty())
        {
            res++;
            int qSize = q.size();

            for (int i = 0; i < qSize; i++)
            {
                auto curr = q.front();
                q.pop();
                int currX = curr.first;
                int currY = curr.second;
                if (arr[curr.first][curr.second] == 1)
                {
                    return res - 1;
                }

                for (int i = 0; i < dx.size(); i++)
                {
                    int newX = currX + dx[i];
                    int newY = currY + dy[i];

                    if (newX >= 0 and newX < rows and newY >= 0 and newY < cols and track[newX][newY] == 0)
                    {
                        track[newX][newY] = 1;
                        q.push(make_pair(newX, newY));
                    }
                }
            }
        }

        return INT32_MAX;
    }

    vector<vector<int>> nearest(vector<vector<int>> arr)
    {
        int rows = arr.size();
        int cols = arr[0].size();

        vector<vector<int>> out(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                out[i][j] = bfs(arr, i, j);
            }
        }
        return out;
    }
};

int main()
{
    vector<vector<int>> arr{{
                                0,
                                1,
                                0,
                                0,
                                1,
                                1,
                                1,
                                1,
                            },
                            {0, 0, 1, 0, 1, 1, 0, 1},
                            {1, 0, 0, 0, 1, 0, 0, 0}};
    Solution ob;

    auto ans = ob.nearest(arr);

    for (auto x : ans)
    {
        for (auto c : x)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}