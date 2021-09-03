class Solution {
public:
int networkDelayTime(vector<vector<int>>& times, int n, int k) 
{
    vector<vector<int>> graph(n, {-1});

    for(int i=0;i<times.size() ;i++)
    {
        times[i][0] = times[i][0] - 1;
        times[i][1] = times[i][1] - 1;
    }
    k--;
    vector<int> temp(n,0);
    vector<vector<int>> weights(n, temp);
    vector<int> currValue(n, INT32_MAX);
    
    unordered_set<int> visited;

    for(auto x: times)
    {
        graph[x[0]].push_back(x[1]);
        weights[x[0]][x[1]] = x[2];
    }   

    currValue[k] = 0;

    queue<int> q;
    q.push(k);
    visited.insert(k);

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();


        for(int node: graph[curr])
        {
            if(node == -1)
            continue;
            if(visited.find(node) == visited.end())
            {
                currValue[node] = min(currValue[node], weights[curr][node]+currValue[curr]);
                q.push(node);
            }
        }
    }
    int max_ = INT32_MIN;

    for(auto x: currValue)
    max_ = max(max_ , x);
    
    cout<<max_<<endl;

    return max_==INT32_MAX?-1:max_;
}
};