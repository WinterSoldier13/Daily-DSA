#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;


//https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/


int longestIncDecSub(vector<int> arr)
{
     int l =arr.size();
     vector<int> lis(l,1);

     //First Filling out all the longest increasing subseq.

     for(int i=1;i<l;i++)
     {
          for(int j =i-1;j>=0;j--)
          {
               if(arr[j]<arr[i])
               {
                    lis[i] = max(lis[i],1+lis[j]);
               }
          }
     }
     // for (int x:lis)
     // {
     //      cout<<x<<" ";
     // }
     // cout<<endl;

     //Now filling out all the decreasing subsequences from arr[i]

     vector<int> lds(l,1);

     for(int i=l-2;i>=0;i--)
     {
          for(int j=i+1;j<l;j++)
          {
               if(arr[j]<arr[i])
               {
                    lds[i] = max(lds[i],1+lds[j]);
               }
          }
     }
     // for (int x:lds)
     // {
     //      cout<<x<<" ";
     // }
     // cout<<endl;
     int max_ = INT32_MIN;

     for(int i=0;i<l;i++)
     {
          max_ = max(max_, lis[i]+lds[i]-1);

     }


     return max_;
}



int main()
{
     vector<int> arr{0,1,2};
     cout<<longestIncDecSub(arr)<<endl;


     return 0;
}