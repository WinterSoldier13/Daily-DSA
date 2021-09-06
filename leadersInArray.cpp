#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    vector<vector<int>> out;
    for(int z = 1;z<=t;z++)
    {
        int n;
        cin>>n;
        vector<int> arr(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        stack<int> stack;

        for(int i =0;i<n;i++)
        {
            int curr = arr[i];
            if(stack.empty())
            {
                stack.push(curr);
                continue;
            }
            if(stack.top()>=curr)
            {
                stack.push(curr);
            }
            else
            {
                while(!stack.empty() and stack.top()<curr)
                {
                    stack.pop();
                }
                stack.push(curr);
            }
            
            
        }
        vector<int> temp;
        while(!stack.empty())
        {
            temp.push_back(stack.top());
            stack.pop();
        }
        reverse(temp.begin(), temp.end());
        out.push_back(temp);

    }
    for(auto x: out)
    {
        for(int c:x)
        cout<<c<<" ";
        cout<<endl;
    }
}