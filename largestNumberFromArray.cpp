#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
public:
    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings
    static bool customCompare(string s1, string s2)
    {
        return s1 + s2 > s2 + s1;
    }
    string printLargest(vector<string> &arr)
    {
        // code here
        sort(arr.begin(), arr.end(), customCompare);

        string res = "";
        for (auto x : arr)
            res += x;
        return res;
    }
};

int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        Solution ob;
        ob.solve(n);
    }

    return 0;
}