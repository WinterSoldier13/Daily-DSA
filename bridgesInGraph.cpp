#include <bits/stdc++.h>
using namespace std;




void dfs(vector<vector<int>> &graph, int curr, int parent, vector<bool> &visited, vector<int> &timeIn, vector<int> &lowTime, int &timer)
{

    // first step mark the current node as visited
    visited[curr] = true;

    // then update both the timeIn and lowTime to the same value
    timeIn[curr] = lowTime[curr] = timer++;

    for(auto node: graph[curr])
    {
        if(node == parent)
            continue;
        
        // if the node has not been visited earlier
        if(visited[node] == false)
        {
            dfs(graph, node, curr, visited, timeIn, lowTime, timer);

            // remember lowTime contains the min of lowTime of all it's neighbours
            lowTime[curr] = min(lowTime[curr], lowTime[node]); // this will make the low time of 'curr' as the min of all it's neighbours 'nodes'

            if(lowTime[node] > timeIn[curr]) // think of it like... if the lowTime[node] < timeIn[curr] => there was a way to visit that node even before we visit it through curr
            {
                // as the lowTime[node] > timeIn[curr] => There is no other way to visit the node, except through the curr
                // => this is a bridge edge
                cout<<"BRIDGE "<<curr<<" "<<node<<endl;
            }
        }

        else
        {
            // if the node has already been visited, do nothing but update it's low time with minimum of it's low or the current inTime
            lowTime[node] = min(lowTime[node], timeIn[curr]);
        }
    }
}


void findBridges(vector<vector<int>> &graph) // graph -> undirected adjancy list
{
    int v = graph.size();

    vector<int> timeIn(v, -1); // stores the time when I visited this node
    vector<int> lowTime(v, -1); // stores the lowest time of all it's neighbours
    vector<bool> visited(v, false); // stores whether I've visited it or not
    int timer = 0;   // this will be a global variable, which will update timeIn

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            dfs(graph, i, -1, visited, timeIn, lowTime, timer);
        }
    }    
}

int main()
{

    return 0;
}