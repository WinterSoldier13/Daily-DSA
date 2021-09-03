#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

int solve(int n, int x, int y, int x_final, int y_final)
{
    vector<int> t(n, 0);
    vector<vector<int>> track(n, t);
    int count = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    vector<int> dx{-2, -2, -1, 1, 2, 2, 1, -1};
    vector<int> dy{-1, 1, 2, 2, 1, -1, -2, -2};

    while (!q.empty())
    {
        count++;
        int qSize = q.size();

        for (int i = 0; i < qSize; i++)
        {
            auto curr = q.front();
            q.pop();

            for (int k = 0; k < 8; k++)
            {
                int newX = curr.first + dx[k];
                int newY = curr.second + dy[k];
                // cout<<"Adding "<<newX<<" "<<newY<<" "<<endl;

                if (newX == x_final and newY == y_final)
                {
                    return count;
                }

                if (newX < 1 or newX > n or newY < 1 or newY > n or track[newX - 1][newY - 1] == 1)
                {
                    // cout<<"Deleting "<<newX<<" "<<newY<<" to the queue"<<endl;
                    continue;
                }
                if (track[newX - 1][newY - 1] == 0)
                {
                    // cout<<"Adding "<<newX<<" "<<newY<<" to the queue"<<endl;
                    q.push(make_pair(newX, newY));
                    track[newX - 1][newY - 1] = 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int x, y;
        cin >> x >> y;

        int x_final, y_final;
        cin >> x_final >> y_final;
        
        if(x == x_final and y==y_final)
        {
            cout<<0<<endl;
            continue;
        }
        cout << solve(n, x, y, x_final, y_final)<<endl;
    }
    return 0;
}