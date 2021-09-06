#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;


// Question 581 LeetCode

vector<int> solve(vector<int> &arr)
{
    int l = arr.size();
    int i=0;
    int j =l-1;
    int min_ = INT32_MAX;
    int max_ = INT32_MIN;

    for(;i<l-1;++i)
    {
        if(arr[i]>arr[i+1])
        {
            break;
        }
    }
    if(i==l-1)
    {
        vector<int> temp{-1};
        return temp;
    }
    for(;j>=0;j--)
    {
        if(arr[j-1]>arr[j])
        {
            break;
        }
    }
    for(int k =i+1;k<=j;k++)
    {
        if(arr[k]>max_)
        {
            max_ = arr[k];
        }
        if(arr[k]<min_)
        {
            min_ = arr[k];
        }
    }
    for(int k=0;k<i;k++)
    {
        if(arr[k]>min_)
        {
            i=k;
            break;
        }
    }
    for(int k=l-1;k>=j+1;k--)
    {
        if(arr[k]<max_)
        {
            j=k;
            break;
        }
    }
    
    vector<int> out{i,j};
    cout<<out[0]<<" "<<out[1]<<endl;
    return out;

}

int main()  
{  
    vector<int> arr{2,1};
    solve(arr);
    

    return 0;  
}  