#include <bits/stdc++.h>
using namespace std;
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
#define ll int
#define endl "\n"

void dijstra(vector<vector<ll>> &graph, ll start, ll end)
{
	ll n = graph.size();
	vector<ll> dist(n, INT_MAX);
	unordered_set<ll> visited;
	priority_queue<pair<ll, ll>> pq;
	dist[start] = 0;
	pq.push({0, start});

	while (!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		ll currNode = curr.second;

		if (visited.count(currNode))
			continue;
		visited.insert(currNode);

		for (ll i = 0; i < n; i++)
		{
			if (graph[currNode][i] == -1)
				continue;

			if (dist[i] > dist[currNode] + graph[currNode][i])
			{
				dist[i] = dist[currNode] + graph[currNode][i];
				pq.push({-dist[i], i});

			}
		}
	}
    if(dist[end] == INT_MAX)
        cout<<0<<endl;
    else
        cout<<1<<endl;
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
		ll u, v, t=1;;
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

	dijstra(graph, a, b);

	return 0;
}