int bfs(vector<vector<int>> &arr, int i, int j)
{
    int rows = arr.size();
    int cols = arr[0].size();
    vector<vector<int>> track = vector<vector<int>>(rows, vector<int> (cols, 0));

    track[i][j] = 1;
    int count = 0;

    queue<pair<int,int>> q;
    q.push({i,j});

    vector<int> dx{-1,0,1,0};
    vector<int> dy{0,1,0,-1};

    while(!q.empty())
    {
        int l = q.size();
        count++;
        for(int i=0;i<l;i++)
        {
            auto curr = q.front();
            q.pop();

            if(arr[curr.first][curr.second] == 3)
                return count;
            for(int i=0;i<4;i++)
            {
                int newX = curr.first+dx[i];
                int newY = curr.second + dy[i];

                if(newX>=0 and newX<rows and newY>=0 and newY<cols)
                {
                    if(track[newX][newY] == 0 and arr[newX][newY] != 1)
                        {
                            track[newX][newY] = 1;
                            q.push({newX, newY});
                        }
                }
            }
        }
    } 
    return INT_MAX;
}
int solve(vector<vector<int>>& arr) 
{
    int rows = arr.size();
    if(rows == 0) return -1;
    int cols = arr[0].size();

    int ans = INT_MAX;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(arr[i][j] == 2)
            {
                ans = min(ans, bfs(arr, i, j));
            }
        }
    }

    return ans==INT_MAX?-1:ans-1;
}