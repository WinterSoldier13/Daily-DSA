class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        set<pair<int,int>> hashset;
        
        
        int l = nums.size();
        if(l==0)
            return 0;
        
        for(int i=0;i<l;i++)
        {
            for(int j=i+1;j<l;j++)
            {
                if(nums[i] == nums[j])
                {
                    hashset.insert(make_pair(i,j));
                }
            }
        }
        
        return hashset.size();
        
        
    }
};