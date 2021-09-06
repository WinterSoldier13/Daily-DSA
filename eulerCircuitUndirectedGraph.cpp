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
public:
    bool isEularCircuitExist(int V, vector<int> adj[])
    {
        vector<int> arr(V, 0);

        for(int i=0;i<V;i++)
        {
            arr[i]+= adj[i].size();
        }

        int countOfVertexWithOddEdges = 0;

        for(int i=0;i<V;i++)
        {
            if(arr[i]%2 != 0)
            {
                countOfVertexWithOddEdges += 1;
                break;
            }
        }

        return countOfVertexWithOddEdges == 0;
    }
};

int main()
{
    fast_cin();
    return 0;
}