#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void recurse(string s, int open, int close, int n)
{
    // cout<<s<<endl;
    if(open>n)
    {
        return;
    }
    if(close == n)
    {
        cout<<s<<endl;
        return;
    }
    
    if(open>close)
    {
        recurse(s+')', open, close+1,n);
    }

    recurse(s+'(', open+1, close, n);
    
    
}
int main()
{
    string s= "(";

    recurse(s,1,0,3);
}