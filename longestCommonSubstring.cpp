#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

int dynamic(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();

    vector<int> t(l2 + 1);
    vector<vector<int>> dp(l1 + 1, t);

    for (int i = 0; i <= l1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= l2; i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int max_ = 0;
    for(auto x: dp)
    {
        max_ = max(max_, *max_element(x.begin(), x.end()));
    }
    return max_;
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s1, s2;
        cin>>s1>>s2;

        cout<<dynamic(s1, s2)<<endl;
    }
    return 1;
}