#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tiii tuple<int, int, int>

class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        int count = 0;
        int sum_ = 0;
        //    sum, countOfSum
        unordered_map<int, int> hashmap;
        hashmap[0] = 1; // for starting index

        for (auto x : arr)
        {
            sum_ += x;
            int req = sum_ - k;
            if (hashmap.find(req) != hashmap.end())
            {
                count += hashmap[req];
            }
            hashmap[sum_]++;
        }
        return count;
    }
};

int main()
{
    vector<int> arr{1, 2, 3, 3, 2, 1, 3, 2};
    // vector<int> arr{1, 1, 1};
    int k = 6;
    Solution ob;

    cout << ob.subarraySum(arr, k) << endl;
}