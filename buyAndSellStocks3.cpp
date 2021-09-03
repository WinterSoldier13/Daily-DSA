#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    void printArr(vector<int> &arr)
    {
        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    int maxProfit(vector<int> &arr)
    {
        int l = arr.size();
        if (l == 0 or l == 1)
        {
            return 0;
        }
        int maxProfit = 0;

        vector<int> dp1(l, 0);
        vector<int> dp2(l, 0);

        // filling it for left to right
        int minVal = arr[0];
        int profit = 0;

        for (int i = 0; i < l; i++)
        {
            minVal = min(minVal, arr[i]);
            profit = max(profit, arr[i] - minVal);
            dp1[i] = profit;
        }
        // printArr(dp1);

        // Filling from right to left
        int maxVal = arr[l - 1];
        profit = 0;
        for (int i = l - 1; i >= 0; i--)
        {
            maxVal = max(maxVal, arr[i]);
            profit = max(profit, maxVal - arr[i]);
            dp2[i] = profit;
        }
        // printArr(dp2);
        // Now max profit = max sum of the two at index i

        int ans = 0;

        for (int i = 0; i < l; i++)
        {
            ans = max(ans, dp1[i] + dp2[i]);
        }

        return ans;
    }
};

int main()
{
    vector<int> arr{3, 3, 5, 0, 0, 3, 1, 4};
    Solution ob;
    cout << ob.maxProfit(arr) << endl;
}