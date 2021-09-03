#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maxLen(int arr[], int n) 
{
    for(int i=0;i<n;i++)
    if(arr[i] == 0)
    arr[i] = -1;

    unordered_map<int, pair<int, int>> hashmap;

    int sum = 0;
    int maxL = 0;
    hashmap[0].first = -1; // To account for the case when the whole array will be the ans
    

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];

        if(hashmap.find(sum) == hashmap.end())
        {
            hashmap[sum].first = i;
            hashmap[sum].second = i;
        }
        else
        {
            hashmap[sum].second = i;
            maxL = max(maxL, (hashmap[sum].second - hashmap[sum].first));
        }
    }
    return maxL;
}

int main()
{
    return 0;
}