#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int mem[101][101];
void init()
{
    for(int i =0;i<101;i++)
    {
        for(int j=0;j<101;j++)
        {
            mem[i][j] = -1;
        }
    }
}

int recurse(int i, int j, int m, int n)
{
    if(mem[i][j]!=-1)
    {
        return mem[i][j];
    }
    if(i==m-1 and j==n-1)
    {
        return mem[i][j]= true;
    }
    if(i<0 or j<0 or i>=m or j>=n)
    {
        return mem[i][j]=false;
    }
    return mem[i][j]=recurse(i+1,j,m,n) + recurse(i,j+1,m,n);
}


int uniquePaths(int m, int n) 
{
    init();
    return recurse(0,0,m,n);
}

int main()
{
    cout<<uniquePaths(23,12)<<endl;
}