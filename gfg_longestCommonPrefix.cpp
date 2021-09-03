#include <iostream>
#include <bits/stdc++.h>
#include<cstring>
#include<stdio.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<string> arr(n,"");

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        string minString="";
        int minLen = INT16_MAX;

        for(auto s: arr)
        {
            if(s.size()<minLen)
            {
                minLen = s.size();
                minString = s;
            }
        }
        // cout<<minString<<endl;

        for(string s: arr)
        {
            int ptr1 = 0;
            int ptr2 = 0;

            while (ptr2<minLen)
            {
                if(s[ptr1] == minString[ptr2])
                {
                    ptr1++;
                    ptr2++;
                }
                else
                {
                    break;
                }
                
            }
            if(ptr1<minLen)
            {
                minLen = ptr1;
                minString = s.substr(0,ptr1);
            }
        }
        if(minString.size() == 0)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<minString<<endl;
    }
}