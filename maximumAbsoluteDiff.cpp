#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli long long int
#define pii pair<int, int>
#define endl '\n'
#define printArr(arr)     \
    for (auto x : arr)    \
        cout << x << " "; \
    cout << endl;
#define printHashmap(hashmap)                                  \
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) \
    {                                                          \
        cout << it->first << " " << it->second << endl;        \
    }
#define print2DArray(arr)     \
    for (auto x : arr)        \
    {                         \
        for (auto c : x)      \
            cout << c << " "; \
        cout << endl;         \
    }

// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    int maxArr(vector<int> &arr);
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int Solution::maxArr(vector<int> &arr)
{
    int l = arr.size();
    int ans = INT_MIN;

    // for (An + n)
    int min_ = INT_MAX;
    int max_ = INT_MIN;

    for (int i = 0; i < l; i++)
    {
        min_ = min(min_, arr[i] + i);
        max_ = max(max_, arr[i] + i);
    }
    ans = max(ans, abs(max_ - min_));

    // for (An - n)
    min_ = INT_MAX;
    max_ = INT_MIN;

    for (int i = 0; i < l; i++)
    {
        min_ = min(min_, arr[i] - i);
        max_ = max(max_, arr[i] - i);
    }
    ans = max(ans, abs(max_ - min_));

    return ans;
}

int main()
{
    fast_cin();

    return 0;
}