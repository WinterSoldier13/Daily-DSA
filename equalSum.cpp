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
private:
    int getTotalSum(int *arr, int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

public:
    string equilibrium(int *arr, int n)
    {
        int totalSum = getTotalSum(arr, n);

        int rightSideSum = totalSum;
        int currentSum = 0;

        for (int i = 0; i <= n - 1; i++)
        {
            currentSum+=arr[i];
            rightSideSum = totalSum - currentSum;

            if(rightSideSum == currentSum-arr[i])
            {
                return "YES";
            }

        }
        return "NO";
    }
};


int main()
{
    fast_cin();
    
    return 0;
}