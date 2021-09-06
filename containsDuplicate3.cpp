#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

// https://leetcode.com/problems/contains-duplicate-iii/discuss/824578/C%2B%2B-O(N)-time-complexity-or-Explained-or-Buckets-or-O(K)-space-complexity
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        int n = nums.size();

        if (n == 0 || k < 0 || t < 0)
            return false;

        unordered_map<int, int> buckets;

        for (int i = 0; i < n; ++i)
        {
            int bucket = nums[i] / ((long)t + 1);

            // For negative numbers, we need to decrement bucket by 1
            // to ensure floor division.
            // For example, -1/2 = 0 but -1 should be put in Bucket[-1].
            // Therefore, decrement by 1.
            if (nums[i] < 0)
                --bucket;

            if (buckets.find(bucket) != buckets.end())
                return true;
            else
            {
                buckets[bucket] = nums[i];
                if (buckets.find(bucket - 1) != buckets.end() && (long)nums[i] - buckets[bucket - 1] <= t)
                    return true;
                if (buckets.find(bucket + 1) != buckets.end() && (long)buckets[bucket + 1] - nums[i] <= t)
                    return true;

                if (buckets.size() > k)
                {
                    int key_to_remove = nums[i - k] / ((long)t + 1);

                    if (nums[i - k] < 0)
                        --key_to_remove;

                    buckets.erase(key_to_remove);
                }
            }
        }

        return false;
    }
};
int main()
{
    vector<int> arr{1, 0, 1, 1};
    int k = 1;
    int t = 2;

    Solution ob;
    cout << ob.containsNearbyAlmostDuplicate(arr, k, t) << endl;

    return 1;
}