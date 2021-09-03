#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

bool backspaceCompare(string s, string t)
{
	int n1 = s.size();
	int n2 = t.size();

	string temp1 = "";
	string temp2 = "";

	for (int i = 0; i < n1; i++)
	{
		char ch = s[i];

		if (ch == '#')
		{
			if (temp1.size() != 0)
			{
				temp1 = temp1.substr(0, temp1.size() - 1);
			}
		}
		else
		{
			temp1 += ch;
		}
	}

	for (int i = 0; i < n2; i++)
	{
		char ch = t[i];

		if (ch == '#')
		{
			if (temp2.size() != 0)
			{
				temp2 = temp2.substr(0, temp2.size() - 1);
			}
		}
		else
		{
			temp2 += ch;
		}
	}
	return temp1 == temp2;
}