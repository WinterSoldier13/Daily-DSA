class Solution {
public:
    int maxSatisfaction(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        int totalSum=0;
        int runningSum =0;
        
        for(auto x: arr)
        {
            runningSum+=x;
            if(runningSum<0)
            {
                break;
            }
            totalSum+=runningSum;
        }
        return totalSum;
        
    }
};
