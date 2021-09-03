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
    int solve(vector<vector<int>> &A);
    int solve2(vector<vector<int>> &A);
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

struct customSort
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
};

int Solution::solve(vector<vector<int>> &arr)
{
    int l = arr.size();
    vector<pair<int, int>> allTheTimes;
    for(auto x: arr)
    {
        allTheTimes.push_back({x[0], 1});
        allTheTimes.push_back({x[1], 0});
    }
    sort(allTheTimes.begin(), allTheTimes.end());

    int rooms = 0;
    int max_ = 0;
    for(auto x: allTheTimes)
    {
        if(x.second == 1)
        {
            rooms++;
            max_ = max(max_, rooms);
        }
        else rooms--;
    }
    cout<<max_<<endl;
    return max_;
}

int main()
{
    fast_cin();

    Solution s;
    vector<vector<int>> arr{{7, 10}, {4, 19}, {19, 26}, {14, 16}, {13, 18}, {16, 21}};

    s.solve(arr);

    return 0;
}
