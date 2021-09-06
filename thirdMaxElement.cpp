class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        set<int> hashset;
        
        for(auto x: nums)
        {
            hashset.insert(x);
        }
        int l = hashset.size();
        
        vector<int> arr(l);
        
        int index = 0;
        for(auto it=hashset.begin();it!=hashset.end();it++)
        {
            arr[index++] = *it;
        }
        if(l<3)
        {
            return arr[l-1];
        }
        else
            return arr[l-3];
    }
};