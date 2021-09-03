#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
public:
    int findSubArraySum(int arr[], int N, int k)
    {
        unordered_map<int, int> hashmap;
        int currentSum = 0;
        int count = 0;
        for(int i=0;i<N;i++)
        {
            currentSum+=arr[i];

            if(currentSum == k)
            {
                count++;
            }

            if(hashmap.find(currentSum-k) != hashmap.end())
            {
                count+=hashmap[currentSum-k];
            }

            hashmap[currentSum]++;
        }

        return count;
    }
};

int main()
{
    fast_cin();

    int n = 3;
    vector<vector<int>> arr{{0, 1, -1}, {1, 2, -2}, {2, 0, 3}};

    return 0;
}