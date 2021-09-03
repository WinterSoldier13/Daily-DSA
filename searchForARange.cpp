#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int findStartIndex(vector<int> arr, int n)
{
    int ans = -1;
    int start = 0;
    int end = arr.size() -1;

    while(start<=end)
    {
        int mid = start + (end-start)/2;

        if(arr[mid]>=n)
        {
            ans = mid;
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
        
    }
    return ans;

}

int findEndIndex(vector<int> arr, int n)
{
    int ans = -1;
    int start = 0;
    int end = arr.size() -1;

    while(start<=end)
    {
        int mid = start + (end-start)/2;

        if(arr[mid]>=n)
        {
            ans = mid;
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    
    }
    return ans;
    
}


vector<int> searchRange(vector<int> &arr, int n)
{
    vector<int> out{-1,-1};

    out[0] = findStartIndex(arr, n);
    out[1] = findEndIndex(arr, n);

    return out;
}

int main()
{
    vector<int> arr{2};
    int n = 2;

    vector<int> temp = searchRange(arr, n);
    for(int c: temp)
    {
        cout<<c<<endl;
    }
}