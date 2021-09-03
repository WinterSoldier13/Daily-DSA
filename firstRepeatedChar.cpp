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
	    
	    unordered_set<char> hashset;
	    bool flag = true;
	    
	    for(char ch: s)
	    {
	        if(hashset.find(ch)!=hashset.end())
	        {
	            cout<<ch<<endl;
	            flag = false;
	            break;
	        }
	        hashset.insert(ch);
	    }
	    if(flag)
	    cout<<-1<<endl;
	}
	return 0;
}