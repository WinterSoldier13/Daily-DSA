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
    int binarySearch(vector<int> arr, int start, int end, int d)
    {
        int ans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] >= d)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> nextPermutation(int n, vector<int> arr)
    {
        int d = -1;

        // step 0: first find a number starting from the right hand side
        // which is less than the previous number
        for (int i = n - 1; i >= 1; i--)
        {
            if (arr[i - 1] < arr[i])
            {
                d = i - 1;
                break;
            }
        }
        if (d == -1)
        {
            reverse(arr.begin(), arr.end());
            return arr;
        }

        // step 1: find the smallest number greater than arr[d] on the right side of d
        int ansIndex = binarySearch(arr, d + 1, n - 1, arr[d]);

        // step2 : Swap them
        swap(arr[d], arr[ansIndex]);

        //step 3 sort from index d+1 to the end
        // remeber it was already in decreasing order

        reverse(arr.begin() + d + 1, arr.end());

        return arr;
    }
};

int main()
{
    fast_cin();
    vector<int> arr{1, 2, 3, 6, 5, 4};
    Solution ob;
    auto ans = ob.nextPermutation(arr.size(), arr);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}