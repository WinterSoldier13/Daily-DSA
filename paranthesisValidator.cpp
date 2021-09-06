#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    
	    stack<char> stack;
	    bool add = true;
	    
	    for(auto x: s)
	    {
	        if(x=='{' or x=='(' or x=='[')
	        {
	        stack.push(x);
	        add= false;
	        }
	        

	        else if(x=='}' and !stack.empty() and stack.top() == '{')
	        stack.pop();
	         
	        else if(x==']' and !stack.empty() and stack.top() == '[')
	        stack.pop();
	        
	        else if(x==')' and !stack.empty() and stack.top() == '(')
	        stack.pop();
	        else if(x=='}' or x==']' or x==')' and stack.empty())
	        {
	            add = true;
	            break;
	        }
	        else
	        break;
	    }
	    if (stack.size()==0 and !add)
	    {
	        cout<<"balanced"<<endl;
	        
	    }
	    else
	    cout<<"not balanced"<<endl;
	}
	
	
	return 0;
}