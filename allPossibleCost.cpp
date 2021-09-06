#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr.size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

vector<int> minCost;
void recurse(vector<vector<int>> &arr, int i, int j, int cost)
{
    int n = arr.size();

    if(i<0 or i>=n or j<0 or j>=n or arr[i][j]<0)
    {
        return;
    }

    if(i==n-1 and j==n-1)
    {
        minCost.push_back(cost);
        return;
    }

    cost+=arr[i][j];
    arr[i][j] *=-1;

    recurse(arr,i-1,j,cost);
    recurse(arr,i,j+1,cost);
    recurse(arr,i+1,j,cost);
    recurse(arr,i,j-1,cost);

    arr[i][j]*=-1;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        init();
        int n;
        cin>>n;
        vector<int> t(n,0);
        vector<vector<int>> arr(n, t);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>> arr[i][j];
            }
        }
        

        recurse(arr, 0,0,0);

        cout<<minCost<<endl;

    }
    return 0;
}
// 31 100 65 12 18 10 13 47 157 6 100 113 174 11 33 88 124 41 20 140 99 32 111 41 20
