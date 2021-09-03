#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

//Minimum Coins to make a value

// let's understand the recursion here
// see in this problem  you start with the sum
// int the next level of the recusrion tree
// you print all the values of sum-arr[i]
// ex sum=11 arr ={1,2,5}
//              11
//            /  |  \\
//           10  8   6
// for each such step the size becomes +1
// most imp you need test a current element for all the available elements in the arr again and again
// i.e here next level of 6 will be 5 4 1 resp..
// so that hints that you need a loop inside the recursion
// Now you need to output the minimum value
// Always remember if for such questions they ask you the minimum value then you need to
// declare res =INT32MAX
// count the local result
// find the min of the two
int recurse(vector<int> arr, int sum)
{
    if (sum == 0)
    {
        return 0;
    }
    int res = INT32_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= sum)
        {
            int local_res = 1 + recurse(arr, sum - arr[i]);
            res = min(res, local_res);
        }
    }

    return res;
}

//Dynamic approach
//https://www.youtube.com/watch?v=jgiZlGzXMBw&t=687s

int coinChange(vector<int> &arr, int sum)
{
    vector<int> dp(sum + 1, INT32_MAX - 1);
    dp[0] = 0;

    for (int i = 1; i < dp.size(); i++)
    {

        for (int j = 0; j < arr.size(); j++)
        {
            int coin = arr[j];
            if (coin <= i)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[sum] == INT32_MAX - 1)
    {
        return -1;
    }
    return dp[sum];
}

int main()
{
    vector<int> arr{1, 2, 5};
    int sum = 11;

    cout << recurse(arr, sum) << endl;
    cout << coinChange(arr, sum) << endl;

    return 0;
}