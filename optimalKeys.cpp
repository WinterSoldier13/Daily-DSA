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
#define MOD 1000000007
#define object Solution ob


// https://practice.geeksforgeeks.org/problems/special-keyboard3018/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&problemStatus=unsolved&page=1&sortBy=submissions&query=category[]Dynamic%20ProgrammingproblemStatusunsolvedpage1sortBysubmissionscategory[]Dynamic%20Programming

class Solution
{
public:
#define lli unsigned long long int

    unsigned long long int optimalKeys(int n)
    {
        vector<lli> dp(n+1);
        dp[0] = -1;
        
        for(int i=1;i<=6;i++)
        {
            dp[i] = i;
        }

        for(int i=7;i<=n;i++)
        {
            lli max_ = 0;
            lli multiplier = 2;
            for(int i = 3;i<n;i++)
            {
                max_ = max(max_, (multiplier++)*dp[n-i] );
            }
            dp[i] = max_;
        }

        return dp[n];
    }
};

int main()
{
    fast_cin();
    object;
    cout<<ob.optimalKeys(75)<<endl;
    return 0;
}
