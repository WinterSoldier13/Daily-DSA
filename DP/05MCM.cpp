#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

int mcm(vector<int> arr, int i, int j)
{
    if(i>=j)
    {
        return 0;
    }
    int minV = INT32_MAX;
    for(int  k= i;k<j;k++)
    {
        // break i to k and k+1 to j
        // Then do voth the function call

        int tempAns = mcm(arr, i,k) + mcm(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        minV = min(minV, tempAns);
    }

}