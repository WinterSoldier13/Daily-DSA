#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

int recurse(vector<int> &arr, int index, int currentCost, unordered_set<int> hashset, int k)
{

    if (index == 0)
    {
        return currentCost;
    }

    int curr = arr[index - 1];
    unordered_set<int> hashset2 = hashset;
    unordered_set<int> hashset3;
    int found = 0;

    if (hashset2.count(curr))
    {
        found = 1;
    }

    hashset2.insert(curr);
    int cost1, cost2;
    if (found)
    {
        cost1 = recurse(arr, index - 1, currentCost + 1, hashset2, k);
    }
    else
    {
        cost1 = recurse(arr, index - 1, currentCost, hashset2, k);
    }

    cost2 = recurse(arr, index - 1, currentCost + k, hashset3, k);

    return min(cost1, cost2);
}

int dynamic(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = k;

    unordered_map<int, int> hashmap;
    hashmap[arr[0]]++;

    for (int i = 1; i < n; i++)
    {
        int occur = 0;
        if (hashmap.find(arr[i]) != hashmap.end())
        {
            occur = hashmap[arr[i]];
            if (occur == 1)
                dp[i] = min(dp[i - 1] + k, dp[i - 1] + 2);
            else
            {
                dp[i] = min(dp[i - 1] + k, dp[i - 1] + 1);
            }
        }
        else
        {
            dp[i] = dp[i - 1];
        }

        hashmap[arr[i]]++;
    }

    return dp[n - 1];
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        unordered_set<int> hashmap;
        sort(arr.begin(), arr.end());
        cout <<"RECURSION " <<1 + recurse(arr, arr.size(), k, hashmap, k) << endl;
        cout << "DYNAMIC " <<dynamic(arr, k) << endl;
    }

    // unordered_set<int> hashmap;
    // vector<int> arr = {3,5,4,5,1};
    // int k = 2;

    // cout << 1+recurse(arr, arr.size(), k, hashmap, k) << endl;
}
