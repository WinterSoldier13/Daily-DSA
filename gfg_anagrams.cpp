#include <iostream>
#include <bits/stdc++.h>
#include<stdio.h>

using namespace std;


int main() {
	//code
	int t;
    cin>>t;
	while(t--)
	{
	    string s1="";
	    string s2="";
	    
	    cin>>s1>>s2;
	    if(s1.size()!=s2.size())
	    {
	    cout<<"NO"<<endl;
	    continue;
	    }
	   
       unordered_map<char, int> hashmap;
       for(char ch: s1)
       hashmap[ch]++;
        bool flag = true;
       for(char ch: s2)
       {
           if(hashmap.find(ch) == hashmap.end() or hashmap[ch] == 0)
           {
               cout<<"NO"<<endl;
               flag = false;
               break;
           }
           else
           hashmap[ch]--;
       }
       if(flag)
       cout<<"YES"<<endl;
	}
	return 0;
}