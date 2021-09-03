#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tup tuple<int, int>


class Solution{
    public:
bool checkSubarraySum(vector<int> &nums, int k)
{
    if (nums.size() < 2)
        return 0;
    k = k == 0 ? INT_MAX : k;
    unordered_map<int, int> um;
    int sum = 0;
    um[0] = -1; 
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (um.find(sum % k) != um.end())
        {
            if (i - um[sum % k] > 1)
                return 1;
        }
        else
        {
            um[sum % k] = i;
        }
    }
    return 0;
}
};