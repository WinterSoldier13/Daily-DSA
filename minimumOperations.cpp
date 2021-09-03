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

class Solution
{
private:
    unordered_map<int, int> hashmap;
public:
    int minOperation(int n)
    {
        int count = 0;

        while(n!=0)
        {
            if(n%2 == 0)
            {
                n/=2;
                count++;
            }
            else
            {
                n-=1;
                count++;
            }
        }
        return count;
        
    }
    // int minOperation(int n)
    // {
    //     vector<int> dp(n+1, INT16_MAX);
    //     dp[0] = 0;
    //     hashmap[0] = 0;
    //     dp[1] = 1;
    //     hashmap[1] = 1;
    //     dp[2] = 2;
    //     hashmap[2] = 2;

    //     if(hashmap.find(n) != hashmap.end())
    //     {
    //         return hashmap[n];
    //     }

    //     for(int i=3;i<=n;i++)
    //     {
    //         for(int j=i-1;j>=1;j--)
    //         {
    //             if(j+1 == i or j*2==i)
    //             {
    //                 dp[i] = min(dp[i], dp[j]+1);
    //                 hashmap[i] = dp[i];
    //             }
    //         }
    //     }
    //     return dp[n];
    // }
};

int main()
{
    fast_cin();

    int n;
    cin>>n;

    object;
    cout<<ob.minOperation(n)<<endl;
    return 0;
}
