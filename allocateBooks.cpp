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
    int books(vector<int> &arr, int b);
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}
int getSum(vector<int> &arr)
{
    int sum = 0;
    for (auto x : arr)
        sum += x;
    return sum;
}
bool allocationPossible(vector<int> &arr, int b, int k)
{
    int count = 1;
    int currentSum = 0;
    int ptr = 0;
    int l = arr.size();
    while (ptr < l)
    {
        currentSum += arr[ptr];

        if (currentSum > k)
        {
            count++;
            currentSum = 0;
            if (count > b)
                return 0;
        }
        else
        {
            ptr++;
        }
    }
    return 1;
}

int Solution::books(vector<int> &arr, int b)
{
    int l = arr.size();
    if (b > l)
        return -1;

    int start = 0;
    int end = getSum(arr);
    int ans = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        cout<<mid<<endl;
        if (allocationPossible(arr, b, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    fast_cin();

    Solution s;
    vector<int> arr{5, 17, 100, 11};
    int b = 4;
    cout << s.books(arr, b) << endl;
    return 0;
}
