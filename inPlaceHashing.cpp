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
    void frequencycount(vector<int> &arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i]--;
        }

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            if (curr >= n)
            {
                curr %= n;
            }
            arr[curr] += n;
        }

        for (int i = 0; i < n; i++)
            arr[i] /= n;
    }
};

int main()
{
    fast_cin();

    return 0;
}