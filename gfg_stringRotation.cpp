#include <iostream>
#include <bits/stdc++.h>
#include<string>
#include<stdio.h>

using namespace std;

string rotateClock(string s)
{
    int l = s.size();
    string part2 = s.substr(l-2, 2);
    string part1 = s.substr(0,l-2);

    return part2+part1;

}

string rotateAnti(string s)
{
    int l = s.size();
    string part2 = s.substr(0, 2);
    string part1 = s.substr(2,l-2);

    return part1+part2;

}


int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;

        if(b.size()!=a.size())
        {
            cout<<0<<endl;
            continue;
        }

        if(rotateAnti(b)==a or rotateClock(b)==a)
        {
            cout<<1<<endl;
            continue;
        }
        cout<<0<<endl;
    }
}