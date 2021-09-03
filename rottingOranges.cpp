#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

// Rotten oranges

class Node
{
public:
    int val;
    int time;
    int x;
    int y;
    Node()
    {
        time = 0;
    }
    Node(int a, int c, int z, int w)
    {
        val = a;
        time = c;
        x = z;
        y = w;
    }
};

vector<vector<Node *>> buildBoard(vector<vector<int>> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();

    vector<vector<Node *>> board(rows, vector<Node *>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Node *node = new Node(arr[i][j], INT16_MAX, i, j);
            board[i][j] = node;
        }
    }
    return board;
}

int bfs(vector<vector<int>> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();
    int time = 0;

    vector<vector<Node *>> board = buildBoard(arr);

    queue<Node *> q;
    vector<vector<int>> track(rows, vector<int>(cols, 0));
    // Pushing all the rotten oranges
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            auto curr = board[i][j];

            if (curr->val == 2)
            {
                curr->time = 0;
                q.push(curr);
            }
        }
    }

    while (!q.empty())
    {
        auto currNode = q.front();
        q.pop();

        int currX = currNode->x;
        int currY = currNode->y;
        int currTime = currNode->time;

        vector<int> dx{-1, 0, 1, 0};
        vector<int> dy{0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newX = currX + dx[i];
            int newY = currY + dy[i];

            if (newX < 0 or newX >= rows or newY < 0 or newY >= cols or track[newX][newY] == 1 or board[newX][newY]->val != 1)
            {
                continue;
            }
            else
            {
                auto oldNode = board[newX][newY];
                oldNode->time = min(oldNode->time, currTime + 1);
                oldNode->val = 2;

                board[newX][newY] = oldNode;
                q.push(oldNode);
                track[newX][newY] = 1;
            }
        }
    }
    // Check if any oranges are left fresh
    // if not then calculate the max time
    time = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // cout << " [" << board[i][j]->val << "," << board[i][j]->time << "] ";
            if (board[i][j]->val == 1)
            {
                return -1;
            }
            if (board[i][j]->val == 2)
                time = max(time, board[i][j]->time);
        }
        // cout << endl;
    }

    return time;
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
        if (r == 0 or c == 0)
        {
            cout << -1;
            continue;
        }

        vector<vector<int>> arr(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
            }
        }
        // for (auto x : arr)
        // {
        //     for (auto c : x)
        //         cout << c << " ";
        //     cout << endl;
        // }
        cout << bfs(arr) << endl;
    }
    return 1;
}