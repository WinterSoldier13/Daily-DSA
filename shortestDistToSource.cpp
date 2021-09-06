#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int dis;
void init()
{
    dis = INT16_MAX;
}
void dfs(vector<vector<int>> &arr, int i, int j, int currDis, int x, int y)
{
    if(i<0 or i>=arr.size() or j<0 or j>=arr[0].size() or arr[i][j]!=1)
    {
        // cout<<"Returning to base from : "<<i<<" "<<j<<endl;
        return;
    }
    if(i == x and j ==y)
    {
        // cout<<"Reached Landing "<<currDis<<endl;
        dis = min(dis, currDis);
        return;
    }

    arr[i][j] = -1;

    dfs(arr, i-1,j, currDis+1,x,y);
    dfs(arr, i,j+1, currDis+1,x,y);
    dfs(arr, i+1,j, currDis+1,x,y);
    dfs(arr, i,j-1, currDis+1,x,y);

    arr[i][j] = 1;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        init();
        int n,m;
        cin>>n>>m;

        vector<int> temp(m,0);
        vector<vector<int>> arr(n,temp);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }

        int x,y;
        cin>>x>>y;

        // for(auto x: arr)
        // {
        //     for(auto c: x)
        //     cout<<c<<" ";
        //     cout<<endl;
        // }

        int currDis = 0;
        dfs(arr, 0,0,currDis,x,y);
        if(dis==INT16_MAX)
        cout<<-1<<endl;
        else
        cout<<dis<<endl;
        dis = 0;

    }
}
