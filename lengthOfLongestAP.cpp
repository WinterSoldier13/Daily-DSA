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
    int lenghtOfLongestAP(int arr[], int n)
    {
        // code here
        int max_ = arr[n-1] - arr[0] +1;
        vector<vector<int>> dp(n, vector<int> (max_, 0));

        if(n==0 or n==1 or n==2)
        {
            return n;
        }
        // for (int i = 0; i < n; i++)
        // {
        //     unordered_map<int, int> temp;
        //     temp[0] = 1;
        //     dp[i] = temp;
        // }
        int maxL = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                int commonDiff = arr[i] - arr[j];

                dp[i][commonDiff] = dp[j][commonDiff] + 1;
                maxL = max(maxL, dp[i][commonDiff]);
            }
        }

        return maxL+1;
    }
};

int main()
{
    fast_cin();
    // int arr[] = {1,7,10,13,14,19};
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution ob;

    cout<<ob.lenghtOfLongestAP(arr, n)<<endl;
    return 0;
}