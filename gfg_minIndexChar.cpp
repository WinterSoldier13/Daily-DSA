#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    
	    string p;
	    cin>>p;
	    
	    unordered_map<char, int> hashmap;
	    
	    for(int i=0;i<s.size();i++)
	    {
	        char ch = s[i];
	        
	        if(hashmap.find(ch) == hashmap.end())
	        {
	            hashmap[ch] = i;
	        }

	    }
	    
	    char minChar= ' ';
	    int minIndex=INT32_MAX-1;
	    
	    for(char ch : p)
	    {
	        if(hashmap.find(ch) != hashmap.end() and hashmap[ch]<minIndex)
	        {
	            minIndex = hashmap[ch];
	            minChar = ch;
	        }
	    }
	    if(minChar == ' ')
	    cout<<"$"<<endl;
	    else
	    cout<<minChar<<endl;
	}
	return 0;
}