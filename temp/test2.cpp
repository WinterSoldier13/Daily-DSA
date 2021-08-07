#include <bits/stdc++.h>
using namespace std;
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
#define ll int
#define endl "\n"

string getString(vector<vector<int>> &graph, int node, vector<char> &arr)
{
	string out = "";
	if(graph[node].size() == 0)
	{
		string temp = "";
		temp.push_back(arr[node]);
		return temp;
	}
	for(auto x: graph[node])
	{
		out += getString(graph, x, arr);
	}
	return out;
}
bool isPallindrome(string s)
{
	string t = s;
	reverse(t.begin(), t.end());
	return t == s;
}
// git commit 12:18:05 by WinterSoldier13
void solve(vector<vector<int>> edges, vector<char> arr, int n, vector<int> queries)
{
	vector<vector<int>> graph(n);
	sort(edges.begin(), edges.end());
	for(auto x: edges)
	{
		graph[x[0]-1].push_back(x[1]-1);
	}

	for(auto q:queries)
	{
		if(isPallindrome(getString(graph,q, arr)))
			cout<<"1"<<endl;
		else cout<<"0"<<endl;
	}

}

int main()
{

	return 0;
}