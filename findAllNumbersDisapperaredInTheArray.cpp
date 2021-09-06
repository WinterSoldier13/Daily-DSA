#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> out;

        for(auto x: nums)
        {
            int index = abs(x) - 1;
            if(nums[index]>0)
            {
                nums[index]*=-1;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                out.push_back(i+1);
            }
        }
        return out;
    }
};