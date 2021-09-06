class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int> hashmap;
        for(int x: nums1)
            hashmap[x]++;
        
        vector<int> out;
        
        for(int x: nums2)
        {
            if(hashmap.find(x)!=hashmap.end() and hashmap[x]>0)
            {
                hashmap.erase(x);
                out.push_back(x);
            }
        }
        
            return out;
        
    }
};