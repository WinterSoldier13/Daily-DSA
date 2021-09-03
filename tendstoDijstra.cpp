#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void runDjistra(vector<vector<int>> &graph)
{
	int n = graph.size();
	// The things we need for djistra
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
	queue<int> q;
	vector<int> track(n, 0);
	vector<int> minDist(n, INT32_MAX);

	minHeap.push(make_pair(0,0));
	minDist[0] = 0;
	track[0] = 1;
	
	// THis will always give me the node at minimum dist
	while(!minHeap.empty())
	{
		int currentNode = minHeap.top().second;
		minHeap.pop();
		track[currentNode] = 1;

		for(auto nodes: graph[currentNode])
		{
			// int edgeWgt = edges[currentNode][nodes];
			int edgeWgt = 1;

			minDist[nodes] = min(minDist[nodes], minDist[currentNode]+edgeWgt );

			if(track[nodes]==0)
			{
				minHeap.push(make_pair(minDist[nodes], nodes));
			}
		}

	}

	// for(auto x: minDist)
	// {
	// 	cout<<x<<" ";
	// }
	// cout<<endl;

	cout<<minDist[n-1]<<endl;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
		{
			cout << n << endl;
			continue;
		}

		vector<vector<int>> graph(n);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					if ((j == i + 1) or ((j + 1) == (3 * (i + 1))))
					{
						graph[i].push_back(j);
					}
				}
			}
		}

		// // Print the graph
		// for (auto x : graph)
		// {
		// 	for (auto c : x)
		// 		cout << c << " ";
		// 	cout << endl;
		// }
		// cout << endl;

		runDjistra(graph);
	}
}