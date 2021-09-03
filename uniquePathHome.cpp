#define MOD 1000000007
vector<int> dijstra(vector<vector<int>> &graph, int n, int start)
{
    vector<int> dist(n, INT_MAX);
    vector<int> track(n, 0);

    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        if(track[curr.second]) continue;
        track[curr.second] = 1;

        for(int i=0;i<n;i++)
        {
            if(graph[curr.second][i] == -1)
                continue;`
            
            if(dist[i] > dist[curr.second] + graph[curr.second][i])
            {
                dist[i] = dist[curr.second] + graph[curr.second][i];
                pq.push({-dist[i], i});
            }
        }
    }
    return dist;
}
unordered_map<int,int> mem;
int dfs(vector<vector<int>> &graph, int curr, int n, vector<int> &dist)
{
    if(mem.find(curr)!=mem.end()) return mem[curr];
    if(curr == n-1)
    {
        return mem[curr]=1;
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(graph[curr][i] == -1 or dist[i]>=dist[curr]) continue;

        // track[i] = 1;
        ans = (ans%MOD + dfs(graph, i, n, dist)%MOD)%MOD;
    }
    return mem[curr]=ans%MOD;
}


int solve(vector<vector<int>>& edges) 
{

    int max_ = 0;
    for(auto x: edges)
        max_ = max(max_, x[1]);

    vector<vector<int>> graph(max_+1, vector<int>(max_+1, -1));
    for(auto x: edges)
    {
        graph[x[0]][x[1]] = x[2];
        graph[x[1]][x[0]] = x[2];
    }
    vector<int> dist = dijstra(graph, max_+1, max_);
    // print1Darray(dist);

    mem.clear();
    return dfs(graph, 0, max_+1, dist);

}
