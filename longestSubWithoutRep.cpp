#include <iostream>
#include <bits/stdc++.h>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        int l = s.size();
        unordered_map<char, int> hashmap;

        int ptr1 = 0;
        int ptr2 = 0;
        int maxL = 1;

        while(ptr2<l)
        {
            char currentChar = s[ptr2];

            if(hashmap.find(currentChar) == hashmap.end())
            {
                hashmap[currentChar] = ptr2;
                maxL = max(maxL, ptr2-ptr1+1);
                
            }
            else
            {
                if(hashmap[currentChar]+1>ptr1)
                {
                    ptr1 = hashmap[currentChar]+1;
                }
                maxL = max(maxL, ptr2-ptr1+1);
                

                hashmap.erase(currentChar);
                hashmap[currentChar] = ptr2;
            }
            ptr2++;

        }
        cout<<maxL<<endl;

    }
}