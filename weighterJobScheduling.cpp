#include <bits/stdc++.h>
using namespace std;

#define lli long long

struct Job
{
	int start;
	int end;
	int profit;
};
struct customSort
{
	bool operator()(Job j1, Job j2)
	{
		return j1.end<j2.end;
	}
};

unordered_map<int, unordered_map<int, int>> mem;
int recurse(vector<Job> &arr, int index, int lastStart)
{
	if(mem.find(index) != mem.end() and mem[index].find(lastStart) != mem[index].end())
	{
		return mem[index][lastStart];
	}

	if(index == 0)
	{
		return 0;
	}
	
	// I can take the current index or I can skip it
	if(arr[index-1].end <= lastStart)
	{
		return mem[index][lastStart] =  max(arr[index-1].profit + recurse(arr, index-1, arr[index-1].start), recurse(arr, index-1, lastStart));
	}
	else
	{
		return mem[index][lastStart] = recurse(arr, index-1, lastStart);
	}
}

int binarySearch(vector<Job> &arr, int index)
{
	int start = 0;
	int end = index-1;
	int ans = -1;
	while (start<=end)
	{
		int mid = start + (end-start)/2;
		if(arr[mid].end <= arr[index].start)
		{
			ans = mid;
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}
	}
	return ans;
}

int nLogN_solution(vector<Job> &arr)
{
	int n = arr.size();
	
	// sort by ascending order of finish time
	sort(arr.begin(), arr.end(), customSort());

	vector<int> dp(n, 0); // This table stores the max profit till index i
	dp[0] = arr[0].profit; // the first Index will obiously have the profit of first job

	for(int i=1;i<n;i++)
	{
		int currentProfit = arr[i].profit; // the profit of current index

		// find the index last job that didn't confict with the current job using bSearch
		int lastJob = binarySearch(arr, i);

		if(lastJob != -1) // if no last job was found whose endTime <= currentStartTime then it will return -1
		{
			currentProfit += dp[lastJob];  // I am adding my currentProfit to the lastJob found profit
		}
		dp[i] = max(dp[i-1], currentProfit); // the max profit at current index will me max of the currentProfit and the profit till the last index
	}
	return dp[n-1];
}

void solve(vector<Job> arr)
{
	int n = arr.size();
	mem.clear();
	sort(arr.begin(), arr.end(), customSort());
	cout<<recurse(arr, n, INT_MAX)<<endl;
	cout<<nLogN_solution(arr)<<endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<Job> arr{{3,5,20}, {2,100,200}, {6,19,100}, {1,2,50}};
	solve(arr);

	return 0;
}