#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    cin>>t;
    int x = 0;
    while(t--)
    {
        string s;
        cin>>s;
        if(s[1] == '+')
        {
            x++;
        }
        else
        {
            x--;
        }
        
    }
    cout<<x<<endl;

}