#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli long long int
#define pii pair<int, int>
#define endl '\n'

class Solution
{
public:
    int binarySearchable(int arr[], int n)
    {
        vector<int> left;
        vector<int> right;

        left.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            left.push_back(max(left[left.size() - 1], arr[i]));
        }

        right.push_back(arr[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            right.push_back(min(right[right.size() - 1], arr[i]));
        }
        reverse(right.begin(), right.end());
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (left[i] <= arr[i] and right[i] >= arr[i])
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    fast_cin();
    int n1, n2;
    cin >> n1 >> n2;

    Solution ob;

    cout << ob.solve(n1, n2) << endl;

    return 0;
}