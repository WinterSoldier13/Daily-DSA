#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
private:
    int v;
    int ans;
    void recurse(vector<vector<int>> &graph, int currentNode, unordered_set<int> &hashset)
    {
        hashset.insert(currentNode);

        if(hashset.size() == v)
        {
            ans = 1;
            return;
        }
        for(auto node: graph[currentNode])
        {
            if(hashset.count(node) == 0)
            {
                recurse(graph, node, hashset);
            }
        }
        hashset.erase(currentNode);
    }

public:
    Solution()
    {
        ans = 0;
    }
    void containsHamiltonianPath(vector<vector<int>> graph)
    {
        v = graph.size();
        unordered_set<int> hashset;

        for(int i=0;i<v;i++)
        {
            if(hashset.count(i) == 0)
            {
                recurse(graph, i, hashset);
            }
            if(ans)
                break;
        }
        cout<<ans<<endl;
    }
};

int main()
{
    fast_cin();

    getT()
    {
        int v,e;
        cin>>v>>e;

        vector<vector<int>> graph(v, vector<int> (0));

        while(e--)
        {
            int U,V;
            cin>>U>>V;
            U--;
            V--;
            graph[U].push_back(V);
            graph[V].push_back(U);
        }

        Solution ob;
        ob.containsHamiltonianPath(graph);
    }

    return 0;
}