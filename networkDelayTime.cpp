#define INF INT32_MAX

class Solution {
public:

int getMinVertex(vector<int> &minDistance, vector<int> &visited)
{
    int minD = INF;
    int vertex = 0;

    int n = minDistance.size();

    for(int i=0;i<n;i++)
    {
        if(minDistance[i]<minD and !visited[i])
        {
            minD = minDistance[i];
            vertex = i;
        }
    }
    return vertex;

}

int networkDelayTime(vector<vector<int>>& times, int n, int src) 
{
    for(int i=0;i<times.size() ;i++)
    {
        times[i][0] = times[i][0] - 1;
        times[i][1] = times[i][1] - 1;
    }
    src--;
    
    vector<int> temp(n,INF);
    vector<vector<int>> graph(n, temp);

    for(auto x: times)
    {
        graph[x[0]][x[1]] = x[2];
    }

    // for(auto x: graph)
    // {
    //     for(int c:x)
    //     {
    //         cout<<c<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> visited(n, 0);
    vector<int> minDistance(n, INF);

    minDistance[src] = 0;

    for(int i=0; i<n; i++)
    {
        int minVertex = getMinVertex(minDistance, visited);
        visited[minVertex] = true;

        for(int j = 0; j<n; j++)
        {
            if(graph[minVertex][j]!=INF and !visited[j])
            {
                minDistance[j] = min(minDistance[j], minDistance[minVertex]+graph[minVertex][j]);
            }
        }

    }

    int max_ = INT32_MIN;
    for(auto x: minDistance)
    max_ = max(max_, x);

    return max_==INF?-1:max_;


    return 1;
}

};