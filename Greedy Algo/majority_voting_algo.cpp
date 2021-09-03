#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;


int majorityElement(vector<int> arr)
{
     int majority_index=0;
     int l = arr.size();
     if(l==0)
     return 0;
     int limit = floor(l/2);
     int count=0;

     for(int i=0;i<l;i++)
     {
          if(arr[i]==arr[majority_index])
          {
               count++;
          }
          else
          {
               count--;
          }
          if(count == 0)
          {
               count=1;
               majority_index=i;
          }
          
     }

     return arr[majority_index];
}


int main()  
{
     vector<int> arr{2,1,2};
     cout<<majorityElement(arr)<<endl;

}  