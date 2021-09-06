#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int t;
    cin>>t;
    for(int z =1;z<=t;z++)
    {
        int n;
        cin>>n;

        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
        cin>>arr[i];

       stack<int> stack;
       vector<pair<int, int>> out;

       for(int i=0;i<n;i++)
       {
           if(stack.empty())
           {
               stack.push(i);
               continue;
           }
           if(stack.size() == 1 and arr[i]>arr[stack.top()])
           {
               stack.push(i);
               continue;
           }
          if(stack.size() == 1 and arr[i]<arr[stack.top()])
           {
               stack.pop();
               stack.push(i);
               continue;
           }

           if(stack.size() == 2 and arr[i]>arr[stack.top()])
           {
               stack.pop();
               stack.push(i);
           }
           else if(stack.size() == 2 and arr[i]<arr[stack.top()])
           {
               int two = stack.top();
               stack.pop();
               int one = stack.top();
               stack.pop();
               stack.push(i);

               out.push_back(make_pair(one, two));
           }
        
       }
       if(stack.size() == 2)
       {
           int two = stack.top();
               stack.pop();
               int one = stack.top();
               stack.pop();
              

               out.push_back(make_pair(one, two));

       }
       if(out.size() ==0)
       cout<<"No Profit";

       
       for(auto x : out)
       {
           cout<<"("<<x.first<<" "<<x.second<<")"<<" ";
       }
       cout<<endl;
        
    }

}