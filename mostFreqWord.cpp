#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
public:
    int count;
    void recurse(vector<int> adj[], int index, int dest)
    {
        if (index == dest)
        {
            count++;
            return;
        }

        for (auto x : adj[index])
        {
            recurse(adj, x, dest);
        }
    }
    int countPaths(int V, vector<int> adj[], int source, int destination)
    {
        count = 0;

        recurse(adj, source, destination);

        return count;
    }
};
int main()
{

    return 0;
}