#include <bits/stdc++.h>
using namespace std;
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
#define ll int
#define endl "\n"

void recurse(vector<vector<int>> &graph, int curr, int end, vector<int> &visited, int & count)
{
    if(curr == end)
    {
        count++;
        return;
    }

    int n = graph.size();
    for(int i=0;i<n;i++)
    {
        if(!visited[i] and graph[curr][i] != -1)
        {
            visited[i] = 1;
            recurse(graph, i, end, visited, count);
        }
    }
}

int main()
{
	fast_cin();
	ll n;
	cin >> n;
	ll currentNode = 0;
	unordered_map<ll, ll> pairNode;
	unordered_map<ll, ll> inversePairNode;

	for (ll i = 0; i < n; i++)
	{
		ll id;
		cin >> id;
		pairNode[id] = currentNode;
		inversePairNode[currentNode] = id;
		currentNode++;
	}

	ll edges;
	cin >> edges;
	vector<vector<ll>> graph(currentNode, vector<ll>(currentNode, -1));

	for (ll i = 0; i < edges; i++)
	{
		ll u, v, t=1;
		cin >> u >> v;
		u = pairNode[u];
		v = pairNode[v];
		graph[u][v] = t;
		graph[v][u] = t;
	}

	ll a, b;
	cin >> a >> b;
	a = pairNode[a];
	b = pairNode[b];

    int count = 0;
    vector<int> track(n+1, 0);
    recurse(graph, a, b, track, count);
    cout<<count<<endl;

	return 0;
}