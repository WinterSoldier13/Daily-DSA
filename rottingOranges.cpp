#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct cell
{
    public:
    int val;
    int timestamp;

    cell(int v, int t)
    {
        val = v;
        timestamp = t;
    }
};


int bfs(vector<vector<int>> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();

    vector<pair<int,int>> dirs{make_pair(-1,0),make_pair(0,1),make_pair(1,0),make_pair(0,-1)};
  
    vector<vector<cell>> grid;
    for(int i=0;i<rows;i++)
    {
        vector<cell> temp;

        for(int j =0 ;j<cols; j++)
        {
            cell x = cell(arr[i][j], 0);
            temp.push_back(x);
        }
        grid.push_back(temp);
    }

    queue<pair<int,int>> q;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(grid[i][j].val == 2)
            {
                q.push(make_pair(i,j));
            }
        }
    }

    while(!q.empty())
    {
        int currentX = q.front().first;
        int currentY = q.front().second;
        int currTimestamp = grid[currentX][currentY].timestamp;

        q.pop();

        for(auto x: dirs)
        {
            int moveX = currentX + x.first;
            int moveY = currentY + x.second;

            if(moveX<0 or moveX>=rows or moveY<0 or moveY>=cols)
            continue;

            if(grid[moveX][moveY].val==1 and grid[moveX][moveY].timestamp == 0)
            {
                if(grid[moveX][moveY].timestamp == 0)
                {
                    grid[moveX][moveY].timestamp++;
                }
                grid[moveX][moveY].val = 2;
                grid[moveX][moveY].timestamp = max(grid[moveX][moveY].timestamp, currTimestamp+1);

                q.push(make_pair(moveX, moveY));
            }
        }
    }

    //Search if any orrange is left unrotten
    
    int max_ = INT32_MIN;
    for(int i = 0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            max_ = max(max_ , grid[i][j].timestamp);
            if(grid[i][j].val == 1)
            {
                return -1;
            }
        }
    }
    return max_;
}

int main()
{
    vector<vector<int>> arr{{2,1,1},
                            {1,1,0},
                            {0,1,1}};

    cout<<bfs(arr)<<endl;
    
    return 0;
}