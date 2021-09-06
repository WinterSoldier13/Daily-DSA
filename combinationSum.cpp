#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tiii tuple<int, int, int, int>

class Solution
{
public:
    vector<vector<int>> mothership;

    void recurse(vector<int> &arr, int sum, vector<int> path)
    {
        if (sum == 0)
        {
            sort(path.begin(), path.end());
            mothership.push_back(path);
            return;
        }
        if (sum < 0)
        {
            return;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            int ele = arr[i];

            if (ele > sum)
            {
                continue;
            }
            path.push_back(ele);
            recurse(arr, sum - ele, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {
        mothership.clear();
        vector<int> temp;
        recurse(arr, target, temp);
        sort(mothership.begin(), mothership.end());
        mothership.erase(unique(mothership.begin(), mothership.end()), mothership.end());
        return mothership;
    }
};