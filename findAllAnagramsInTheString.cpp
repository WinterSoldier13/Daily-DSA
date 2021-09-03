#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

// vector<int> findAnagrams(string s, string p) 
// {
// 	sort(p.begin(), p.end());

// 	int l = s.size();
// 	int l2 = p.size();
// 	vector<int> out;

// 	for(int i=0;i<=l-l2;i++)
// 	{
// 		string temp = s.substr(i, l2);
		
// 		sort(temp.begin(), temp.end());
// 		if (temp == p)
// 		{
// 			out.push_back(i);
// 		}
// 	}
// 	for (auto x: out)
// 	{
// 		cout<<x<<endl;
// 	}
// 	return out;
// }

// int findSum(vector<int> map_)
// {
// 	int sum_ =0;
// 	for(auto x: map_)
// 	{
// 		sum_+=x;
// 	}
// 	return sum_;
// }


// vector<int> findAnagrams(string s, string p)
// {
// 	int l1 = s.size();
// 	int l2 = p.size();

// 	vector<int> map_(256,0);

// 	for(auto ch: p)
// 	{
// 		map_[ch]++;
// 	}


// 	int ptr=0;

// 	vector<int> out;
// 	vector<int> temp = map_;

// 	for(int i=0;i<=l1-l2;i++)
// 	{
// 		bool flag = true;
// 		for(int j=i;j<=i+l2;j++)
// 		{
// 			if(temp[s[j]]!=0)
// 			{
// 				temp[s[j]]--;
// 			}
// 			else
// 			{
// 				flag = false;
// 				break;
// 			}
// 		}
// 		if(findSum(temp) == 0 and !flag)
// 		{
// 			out.push_back(i);
// 		}
// 		temp = map_;
// 	}

// 	for(auto x: out)
// 		cout<<x<<" ";
// 	cout<<endl;

// 	return out;

// }

class Solution {
public:

void print(vector<int> arr)
{
	for(auto x: arr)
	cout<<x<<" ";
	cout<<endl;
}
int findZero(vector<int> arr)
{
	for(auto x: arr)
	if(x!=0)
	return false;
	return true;
}
vector<int> findAnagrams(string s, string p)
{
	int l1 = s.size();
	int l2 = p.size();

	vector<int> track(26, 0);
	vector<int> out;
    
    if(l1==0 or l2==0 or (l2>l1))
    {
        return out;
    }

	// First Window
	for(int i=0;i<l2;i++)
	{
		char ch1 = s[i];
		char ch2 = p[i];

		track[ch1-'a']++;
		track[ch2-'a']--;

		print(track);
	}

	if(findZero(track))
	{
		out.push_back(0);
	}

	for(int i=1;i<=l1-l2;i++)
	{
		char removedCh = s[i-1];
		char addedCh   = s[i+l2 -1];

		track[removedCh - 'a']--;
		track[addedCh   - 'a']++;

		if(findZero(track))
		{
			out.push_back(i);
		}
	}

	for(auto x: out)
	{
		cout<<x<<endl;
	}
	return out;
}

};


int main()
{
	string s = "cbaebabacd";
	string p = "abc";

	findAnagrams(s,p);
}