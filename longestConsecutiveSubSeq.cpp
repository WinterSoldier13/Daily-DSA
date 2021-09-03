
// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers

#include<bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int n)
{
  //Your code he
  priority_queue<int, vector<int>, greater<int>> minHeap;
  
  for(int i=0;i<n;i++)
  {
      minHeap.push(arr[i]);
  }
  vector<int> a;
  while(!minHeap.empty())
  {
      a.push_back(minHeap.top());
      minHeap.pop();
  }
  
  for(int x: a)
  {
      cout<<x<<endl;
  }
  cout<<endl<<endl;
  
  int ptr1 = 0;
  int ptr2 = 1;
  int maxL = 0;
  
  while(ptr2<a.size())
  {
      if(a[ptr2]-a[ptr2-1] == 0)
      {
          ptr2++;
      }
      else
      {
          maxL = max(maxL, ptr2-ptr1);
          ptr1 = ptr2++;
      }
  }
  
  a.clear();
  cout<<"MAX"<<maxL<<endl;
}