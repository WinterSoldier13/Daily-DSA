#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool flag;
void recurse(vector<vector<int>> &grid, int i, int j, int n)
{

    if(i<0 or j<0 or i>=n or j>=n or grid[i][j] == 0)
    {
        return;
    }
        if(grid[i][j] == 2)
    {
        flag = true;
        return;
    }
    int temp = grid[i][j];
    grid[i][j] = 0;
    
    recurse(grid, i-1,j,n);
    recurse(grid, i+1,j,n);
    recurse(grid, i,j-1,n);
    recurse(grid, i,j+1,n);
    
    grid[i][j] = temp;
    
    
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        flag = false;
        cin>>n;
        vector<int> temp(n,-1);
        vector<vector<int>> arr(n, temp);
        
        int x,y;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j] == 1)
                {x=i;y=j;}
            }
        }
        
        recurse(arr, x,y,n);
        if(flag)
        cout<<1<<endl;
        else
        cout<<0<<endl;
    }
    
    

}