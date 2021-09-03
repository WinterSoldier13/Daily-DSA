#include<iostream>
#include<bits/stdc++.h>

using namespace std;


//recursice

static int dp[1001][1001];

void init()
{
    for (int i=0;i<1001;i++)
    for (int j=0;j<1001;j++)
    dp[i][j] = -1;
}

int recurse(vector<int> arr, int i, int j)
{
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(i>=j)
    {
        return dp[i][j]= 0;
    }

    int final_ = INT32_MAX-1;
    for(int k=i;k<j;k++)
    {
        int part1 = recurse(arr,i,k);
        int part2 = recurse(arr,k+1,j);
        int ccost = arr[i-1] * arr[k] * arr[j];

        int temp = part1 + part2 + ccost;
        
        final_ = min(final_, temp);
    }

    return dp[i][j]= final_;

}

int main()
{
    vector<int> arr{40, 20, 30, 10, 30};
    init();
    cout<<recurse(arr, 1, arr.size()-1)<<endl;
    init();


    return 0;
}