#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void combinations(string s, int i, string t)
{
    if(i == s.size()-1)
    {
        cout<<t<<endl;
        t+=s[i];
        cout<<t<<endl;
        return;
    }
    combinations(s, i+1, t);
    t+=s[i];
    combinations(s,i+1,t);

}

int main()
{
    string s = "abc";
    string t="";
    combinations(s,0,t);
}