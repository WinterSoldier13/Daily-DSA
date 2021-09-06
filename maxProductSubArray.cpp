#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;


int maxProduct(vector<int> arr)
{
    int finalMax = arr[0];
    int currentMax = arr[0];
    int currentMin = arr[0];
    int prevMin =arr[0];
    int prevMax = arr[0];

    for(int i=1;i<arr.size();i++)
    {
        currentMax = max(prevMin*arr[i], max(arr[i], prevMax*arr[i]));
        currentMin = min(prevMin*arr[i], min(arr[i], prevMax*arr[i]));
        finalMax = max(finalMax, currentMax);
        prevMin = currentMin;
        prevMax = currentMax;
    }

    return finalMax;

}

int main()
{
    vector<int> arr{-4,-3,-2};
    int pr = 1;

    cout<<maxProduct(arr)<<endl;
}