#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

vector<int> findKeysOfHashmap(unordered_map<int,int> &hashmap)
{
	vector<int> out;

	for(auto it = hashmap.begin(); it!=hashmap.end();it++)
	{
		out.push_back(it->first);
	}
	return out;
}


int totalFruit(vector<int>& arr) 
{
	int n = arr.size();
	int ptr1 =0;
	int ptr2 =0;

	// Store element, lastIndexOfOccur
	unordered_map<int, int> hashmap;
	int maxL = 0;

	while(ptr2<n)
	{
		int curr = arr[ptr2];

		if(hashmap.size()<2)
		{
			hashmap[curr] = ptr2;
			ptr2++;
		}
		else if(hashmap.find(curr) != hashmap.end())
		{
			hashmap[curr] = ptr2;
			ptr2++;
		}
		else
		{
			int prevEle = arr[ptr2-1];
			vector<int> theTwoEle = findKeysOfHashmap(hashmap);
			int theOtherElement = theTwoEle[0]==prevEle?theTwoEle[1]:theTwoEle[0];

			maxL = max(maxL, ptr2-ptr1);
			ptr1 = hashmap[theOtherElement]+1;
			hashmap.erase(theOtherElement);
			hashmap[curr] = ptr2;
		}
	}
	vector<int> theTwoEle = findKeysOfHashmap(hashmap);
	maxL = max(maxL, ptr2- ptr1);
	return maxL;
}

int main()
{
	vector<int> arr{1,2,3,2,2};
	cout<<totalFruit(arr)<<endl;

	return 0;
}
