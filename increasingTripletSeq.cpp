class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        if(nums.size() < 3) 
            return false;
        
        int a = INT_MAX, b = INT_MAX;
        
        
        for(int ele: nums) 
        {
            if(ele <= a) 
                a = ele;
            else if(ele <= b)
                b = ele;
            else 
                return true;
        }
        return false;
    }
};