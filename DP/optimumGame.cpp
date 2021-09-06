#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;

static int turn=0;
static int my_val1=0;
static int my_val2=0;

int optimumGame(vector<int> arr, int start, int end)
{
    if(start+1==end)
    {
        return max(arr[start],arr[end]);
    }

    else
    {
        return max((arr[start]+min(optimumGame(arr,start+2,end),optimumGame(arr,start+1,end-1))),
                    arr[end]+min(optimumGame(arr,start+1,end-1),optimumGame(arr,start,end-2))
        );
    }
}


int main()
{
    vector<int> arr{20,5,4,6};
    cout<<optimumGame(arr,0,arr.size()-1);
    return 0;
}