#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

vector<vector<int>> mem;

void __init__(int n, int k)
{
    vector<int> t(k+1,-1);
    vector<vector<int>> temp (n+1,t);
    mem = temp;
}

int mcm(int egg, int floor)
{
    if(mem[egg][floor] != -1)
    {
        return mem[egg][floor];
    }
    if(floor == 0 or floor == 1 or egg==1)
    {
        return mem[egg][floor]=floor;
    }

    int min_ = INT32_MAX;

    for(int k=1;k<=floor;k++)
    {
        int tempAns = 1+max( mcm(egg-1, k-1), mcm(egg, floor-k));

        min_ = min(min_ , tempAns);
    }
    return mem[egg][floor]=min_;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        __init__(n,k);
        cout<<mcm(n,k)<<endl;
    }
}