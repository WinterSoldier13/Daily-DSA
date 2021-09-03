#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

class Solution
{
public:
    int k;
    vector<vector<int>> mothership;
    void __init__(int target)
    {
        k = target;
        mothership.clear();
    }
    int findSum(vector<int> &arr)
    {
        int sum_ = 0;
        for (auto x : arr)
        {
            sum_ += x;
        }
        return sum_;
    }
    void recurse(vector<int> &arr, int index, vector<int> temp)
    {
        if (index == arr.size() - 1)
        {
            if (findSum(temp) == k)
            {
                sort(temp.begin(), temp.end());
                mothership.push_back(temp);
            }
            temp.push_back(arr[index]);

            if (findSum(temp) == k)
            {
                sort(temp.begin(), temp.end());
                mothership.push_back(temp);
            }
            return;
        }
        if (findSum(temp) <= k)
            recurse(arr, index + 1, temp);
        temp.push_back(arr[index]);
        if (findSum(temp) <= k)
            recurse(arr, index + 1, temp);
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        __init__(target);
        vector<int> temp;
        recurse(candidates, 0, temp);
        sort(mothership.begin(), mothership.end());
        mothership.erase(unique(mothership.begin(), mothership.end()), mothership.end());
        return mothership;
    }
};