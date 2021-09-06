#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minPrice = INT32_MAX;
        int maxProfit = 0;
        
        for(int i=0;i<prices.size();i++)
        {
            int currPrice = prices[i];
            minPrice = min(minPrice, currPrice);
            maxProfit = max(maxProfit, currPrice - minPrice);
        }
        return maxProfit;
        
    }
};