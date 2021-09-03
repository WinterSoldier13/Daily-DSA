class Solution
{
public:
	// vector<int> memory;
	map<int, int> memory;


	void __init__(int n)
	{
		// vector<int> temp(n+1, -1);
		// memory = temp;
		// temp.clear();
		memory[n] = 1;
	}
	bool recurse(int currentIndex, int prevJump, int lastIndex, unordered_set<int> &hashset)
	{
		if(memory.find(currentIndex)!=memory.end())
		{
			return memory[currentIndex];
		}
		if (currentIndex >= lastIndex)
		{
			return memory[currentIndex] = true;
		}
		int value1 = prevJump - 1;
		int value2 = prevJump;
		int value3 = prevJump + 1;

		bool flag = false;

		if (value1 > 0 and hashset.count(currentIndex + value1))
		{
			if (recurse(currentIndex + value1, value1, lastIndex, hashset))
			{
				flag = true;
			}
		}
		if (hashset.count(currentIndex + value2))
		{
			if (recurse(currentIndex + value2, value2, lastIndex, hashset))
			{
				flag = true;
			}
		}
		if (hashset.count(currentIndex + value3))
		{
			if (recurse(currentIndex + value3, value3, lastIndex, hashset))
			{
				flag = true;
			}
		}
		return memory[currentIndex] = flag;
	}

	bool canCross(vector<int> &stones)
	{
		unordered_set<int> hashset;
		__init__(stones[stones.size() - 1]);

		for (int x : stones)
		{
			hashset.insert(x);
		}

		if (stones[1] != 1)
		{
			return false;
		}
		return recurse(1, 1, stones[stones.size() - 1], hashset);
	}
};


int main()
{
	Solution ob = Solution();
	vector<int> arr{0,1,3,5,6,8,12,17};
	ob.canCross(arr);
}

// With memorization
class Solution {
public:
    unordered_map<int, unordered_map<int,int>> memo; //{memo[i][j] : i = stone index, j = steps taken to reach the index}
    int ans = false;
    unordered_map<int,int> stonesSet; //{key = stone; value = stone index}
    void checkJumps(int i, int k, vector<int>& stones){
        if(memo[i][k] || ans)
            return;
        memo[i][k] = 1;
        if(i==stones.size()-1){
            ans = true;
            return;
        }            
        if(k-1!=0 && stonesSet.find(stones[i]+k-1)!=stonesSet.end())
            checkJumps(stonesSet[stones[i]+k-1],k-1, stones);
        if(k!=0 && stonesSet.find(stones[i]+k)!=stonesSet.end())
            checkJumps(stonesSet[stones[i]+k],k, stones);
        if(stonesSet.find(stones[i]+k+1)!=stonesSet.end())
            checkJumps(stonesSet[stones[i]+k+1],k+1, stones);
        return;            
    }
    bool canCross(vector<int>& stones) {
        int size = stones.size();
        for(int i=0; i<size; i++)
            stonesSet[stones[i]] = i;
        checkJumps(0,0,stones);
        return ans;
    }
};