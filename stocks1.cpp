// STONKS --->>>> LOL
class Solution {

public:
    int maxProfit(vector<int>& arr) 
    {
        int minPrice = INT32_MAX;
        int maxProfit = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<minPrice)
            {
                minPrice = arr[i];
            }
            else if(arr[i]-minPrice>maxProfit)
                maxProfit = arr[i]-minPrice;
        }
        return maxProfit;
    }
};