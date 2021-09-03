#include<bits/stdc++.h>
using namespace std;

// int jump(vector<int>& nums)
// {
//     int l = nums.size();
//     vector<int> dp(l,INT32_MAX);

//     dp[0] = 0;

//     for(int i=1;i<l;i++)
//     {
//         int min_ = dp[i];

//         for(int j =i-1;j>=0;j--)
//         {
//             int ele = nums[j];
//             if(j+nums[j]>=i)
//             {
//                 min_ = min(min_, 1+dp[j]);
//             }
//         }
//         dp[i] = min_;

//     }

//     for(auto x: dp)
//     {
//         cout<<x<<" ";
//     }
//     cout<<endl;
//     return dp[l-1];
// }


int jump(vector<int> &nums)
{
     int l = nums.size();
     
    if(l == 0 or nums[0]==0)
    {
        return 0;
    }
    if(nums[0] == 1 and l == 1)
    {
        return 0;
    }

    int maxIndexReachable = nums[0];
    int jumps = 1;
    int limit = nums[0];

    for(int i=1;i<l;i++)
    {
        if(i>limit)
        {
            jumps++;
            limit = maxIndexReachable;
        }
        maxIndexReachable = max(maxIndexReachable, i+nums[i]);
    }
    return jumps;
}

int main()
{
    vector<int> num{2,3,1,1,4};
    cout<<jump(num)<<endl;

    return 1;
}