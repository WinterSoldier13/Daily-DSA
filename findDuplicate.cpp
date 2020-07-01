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