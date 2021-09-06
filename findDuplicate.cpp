class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int num : nums)
        {
            if(hashset.find(num)!=hashset.end())
            {
                return num;
            }
            hashset.insert(num);
        }
        return -1;
        
    }
};



// Another way
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                return nums[i];
            }
        }
        return -1;
        
    }
};