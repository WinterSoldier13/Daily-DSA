#include <bits/stdc++.h>
using namespace std;
#define lli long long int

class Solution{
    public:

        int maxSum(int n){

            vector<int> dp(n+1,0);
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 2;

            for(int i=3;i<=n;i++)
            {
                dp[i] = max(i, dp[(int)i/2] + dp[(int)i/3] + dp[(int)i/4]);
            }

            return dp[n];
        }
};


int main()
{
    Solution ob;
    int n;
    cin>>n;
    cout<<ob.maxSum(n)<<endl;
    return 0;
}