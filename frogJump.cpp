#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// DFS

bool recurse(int currentIndex, int prevJump, int lastIndex, unordered_set<int> &hashset)
{
	if(currentIndex>=lastIndex)
	{
		return true;
	}
	int value1 = prevJump-1;
	int value2 = prevJump;
	int value3 = prevJump+1;

	bool flag = false;

	if(value1>0 and hashset.count(currentIndex+value1))
	{
		if(recurse(currentIndex+value1, value1, lastIndex, hashset))
		{
			flag = true;
		}
	}
	if(hashset.count(currentIndex+value2))
	{
		if(recurse(currentIndex+value2, value2, lastIndex, hashset))
		{
			flag = true;
		}
	}
	if(hashset.count(currentIndex+value3))
	{
		if(recurse(currentIndex+value3, value3, lastIndex, hashset))
		{
			flag = true;
		}
	}
	return flag;
	
}

bool canCross(vector<int>& stones) 
{
	unordered_set<int> hashset;
	for(int x: stones)
	{
		hashset.insert(x);
	}

	if(stones[1]!=1)
	{
		return false;
	}
	return recurse(1,1,stones[stones.size()-1],hashset);
	
}

int main()
{
	vector<int> stones{0,1,3,5,6,8,12,17};
	cout<<canCross(stones)<<endl;
}