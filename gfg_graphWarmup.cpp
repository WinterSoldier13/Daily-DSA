#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int v,e;
        cin>>v>>e;
        vector<int> temp;
        vector<vector<int>> graph(v,temp );

        for(int i=0;i<e;i++)
        {
            int node1, node2;
            cin>>node1>>node2;

            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        for(int i=0;i<v;i++)
        {
            cout<<i;
            for(auto x: graph[i])
            {
                cout<<"-> "<<x;
            }
            cout<<endl;
        }
    }
}