#include <bits/stdc++.h>

using namespace std;

bool valid(vector<vector<int>>&grid,int n,int m,int val,int x,int y)
{
	for(int j=0;j<=m-1;j++)
	{
		if(grid[x][j]==val)
		{
			return false;
		}
	}
	for(int i=0;i<=n-1;i++)
	{
		if(grid[i][y]==val)
		{
			return false;
		}
	}
	int ri=x/3*3;
	int ci=y/3*3;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(grid[ri+i][ci+j]==val)
			{
				return false;
			}
		}
	}
	return true;
}




void solve(vector<vector<int> >&grid,int i,int j,int n,int m)
{
	if(i==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
		return;
		
	}
	int ni=0;
	int nj=0;
	if(nj==n-1)
	{
		nj=0;
		ni=i+1;
	}
	else
	{
		nj=j+1;
		ni=i;
	}
	if(grid[i][j]!=0)
	{
		solve(grid,ni,nj,n,m);
	}
	else
	{
		for(int pos=1;pos<=9;pos++)
		{
			if(valid(grid,n,m,pos,i,j)==true)
			{
				grid[i][j]=pos;
				solve(grid,ni,nj,n,m);
				grid[i][j]=0;
			}
		}

	}
	
}


int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > grid(n,vector<int>(m,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>grid[i][j];
		}
	}
	solve(grid,0,0,n,m);
	



    return 0;
}