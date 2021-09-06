#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int kadane(int arr[], int n)
{
    int localMax = 0;
    int globalMax = INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        localMax = max(arr[i], arr[i]+localMax);
        
        globalMax = max(globalMax, localMax);
        
        if(localMax <0)
        localMax = 0;
    }
    return globalMax;
}

int circularSubarraySum(int arr[], int num){

    if(num == 1)
    {
        return arr[0];
    }
    // your code here
    int ans1= kadane(arr, num);
    
    int totalSum = 0;
    for(int i = 0;i<num;i++)
    {
        totalSum+=arr[i];
        arr[i]*=-1;
    }
    
    int ans2 = totalSum + kadane(arr, num);
    
    // cout<<ans1<<" "<<ans2<<endl;
    if(ans2 == 0)
    {
        return ans1;
    }
    return max(ans1, ans2);
}

int main()
{
    return 0;
}