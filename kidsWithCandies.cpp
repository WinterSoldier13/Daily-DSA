class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        // int min_=minimum_element(candies);
        int max_=*max_element(candies.begin(), candies.end());
        
        vector<bool> out;
        
        for(auto x: candies)
        {
            if(x+extraCandies >= max_)
            {
                    out.push_back(true);
            }
            else
                out.push_back(false);
        }
        return out;
        
        
    }
};