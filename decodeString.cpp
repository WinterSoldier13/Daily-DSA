#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

string decodeString(string s)
{
	stack<int> count;
	stack<string> results;

	string res="";
	int ptr = 0;
	while(ptr<s.size())
	{
		char ch = s[ptr];

		if(isdigit(ch))
		{
			
			int num = 0;
			while(isdigit(s[ptr]))
			{
				num = (10)*num + (s[ptr]-'0');
				ptr++;
			}
			cout<<num<<endl;
			count.push(num);
		}
		else if (ch == '[')
		{
			results.push(res);
			res = "";
			ptr++;
		}
		else if(ch == ']')
		{
			string temp = results.top();
			results.pop();
			for(int i=0;i<count.top();i++)
			{
				temp+=res;
			}
			count.pop();
			res = temp;
			ptr++;
		}
		else
		{
			res = res+ch;
			ptr++;
		}
	}
	return res;
}

int main()
{
	string s = "300[a2[c]]";
	cout<<decodeString(s)<<endl;
	return 0;
}
