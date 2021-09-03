#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> mothership;

void permute(string arr, int start, int end)
{
    if(start == end)
    {
        cout<<arr<<endl;
        return;
    }

    for(int i=start;i<end;i++)
    {
        swap(arr[start], arr[i]);
        permute(arr,start+1, end);
        swap(arr[start], arr[i]);
    }
}

int main()
{
    string arr="";
    permute(arr,0,arr.size());
    return 0;
}