#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define tiii tuple<int, int, int>

vector<vector<int>> makeBoard(int r, int c)
{
    vector<vector<int>> arr(r, vector<int>(c, 0));
    return arr;
}

int bfs(int x1, int y1, int x2, int y2, int r, int c)
{
    int min_ = INT16_MAX;
    queue<tiii> q;
    set<pair<int, int>> tracker;

    q.push(make_tuple(x1 - 1, y1 - 1, 0));
    tracker.insert(make_pair(x1 - 1, y1 - 1));

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int x = get<0>(curr);
        int y = get<1>(curr);
        int d = get<2>(curr);

        // cout<<x<<" "<<y<<" "<<d<<endl;

        if (x == x2 - 1 and y == y2 - 1)
        {
            return d;
        }
        vector<int> dx{-2, -2, 2, 2, -1, -1, 1, 1};
        vector<int> dy{-1, 1, -1, 1, -2, 2, -2, 2};

        for (int i = 0; i < 8; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 0 or newX >= r or newY < 0 or newY >= c or tracker.count({newX, newY}))
            {
                continue;
            }
            else
            {
                q.push(make_tuple(newX, newY, d + 1));
                tracker.insert({newX, newY});
            }
        }
    }
    return -1;
}

int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout<<bfs(x1,y1,x2,y2,r,c)<<endl;
    }
}