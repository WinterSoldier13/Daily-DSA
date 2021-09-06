#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;


//https://www.interviewbit.com/problems/seats/


int seats(string s)
{
     long long l = s.size();
     vector<long long> pos;

     for(long long i=0;i<l;i++)
     {    if(s[i]=='x')
          {
               pos.push_back(i);

          }
         
     }
     long long l2 = pos.size();


     if(l2==0 or l2==1)
         return 0;


     long long median_index = l2/2;

     long long front = median_index;
     long long back = l2-1-median_index;

     long long index_in_string = pos[median_index];

     vector<long long> front_indices;
     vector<long long> back_indices;

     while (front)
     {
          front_indices.push_back(--index_in_string);
          front--;
     }
     index_in_string = pos[median_index];
     while (back)
     {
          back_indices.push_back(++index_in_string);
          back--;
     }

     reverse(front_indices.begin(),front_indices.end());
     for(int x: front_indices)
     cout<<x<<" ";
     cout<<endl;
     for(int x: back_indices)
     cout<<x<<" ";
     cout<<endl;

     long long sum =0;

     for(long long i =median_index-1;i>=0;i--)
     {
          sum+=abs(front_indices[i]-pos[i]);

     }
     long long j=0;
     for(long long i =median_index+1;i<l2;i++)
     {
          sum+=abs(back_indices[j]-pos[i]);
          j++;

     }

     return sum;




     


}


int main()  
{
     string s ="....x..xx...x..";
     cout<<seats(s)<<endl;

}  