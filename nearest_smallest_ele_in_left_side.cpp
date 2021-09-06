#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;

// Find the nearest smaller numbers on left side in an array - GeeksforGeeks

vector<int> prevSmaller(vector<int> A)
{
    int l = A.size();
    int i=0;
    int j=0;
    vector<int> out(l,0);
    stack<int> stack;

    for(int i=0;i<l;i++)
    {
        while(!stack.empty() && stack.top()>A[i])
        {
            stack.pop();
        }
        if(stack.empty())
        out[i]=-1;
        else
        {
            out[i] = stack.top();
        }
        stack.push(A[i]);
        
    }
    return out;
}



int main()  
{  
    vector<int> arr{ 34, 35, 27, 42, 5, 28, 39, 20, 28};
    for(auto x: prevSmaller(arr))
    {
        cout<<x<<endl;
    }
    

    
    return 0;  
}  