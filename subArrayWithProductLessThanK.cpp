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
#define printArr(arr)     \
    for (auto x : arr)    \
        cout << x << " "; \
    cout << endl;

class Solution
{
private:
    int getProduct(vector<int> &arr)
    {
        if (arr.size() == 0)
        {
            return INT_MAX;
        }
        int pr = 1;
        for (auto x : arr)
        {
            pr *= x;
        }
        return pr;
    }

    void recurse(vector<int> arr, vector<int> &mothership, int k)
    {
        for (int i = 0; i < (1 << arr.size()); i++)
        {
            long long value = 1;
            for (int j = 0; j < arr.size(); j++)
            {
                if (i & (1 << j))
                    value *= arr[j];
            }
            if (value <= k)
                mothership.push_back(value);
        }
    }

    int getUpperBound(vector<int> &arr, int k)
    {
        return distance(arr.begin(), upper_bound(arr.begin(), arr.end(), k));
    }

public:
    int numOfSubsets(int arr[], int N, int K)
    {
        // meet in the middle approach
        vector<int> part1;
        vector<int> part2;

        for (int i = 0; i < N / 2; i++)
        {
            part1.push_back(arr[i]);
        }
        for (int i = N / 2; i < N; i++)
        {
            part2.push_back(arr[i]);
        }

        vector<int> product1;
        vector<int> product2;

        printArr(part1);
        printArr(part2);

        recurse(part1, product1, K);
        recurse(part2, product2, K);

        sort(product1.begin(), product1.end());
        sort(product2.begin(), product2.end());

        printArr(product1);
        printArr(product2);

        int ans = 0;
        for (auto x : product1)
        {
            int limit = K / x;
            ans += getUpperBound(product2, limit);
        }

        return ans - 1;
    }
};

int main()
{
    fast_cin();

    int arr[] = {2, 4, 5, 3};
    int N = 4;
    int K = 12;

    Solution ob;
    auto ans = ob.numOfSubsets(arr, N, K);

    cout << ans << endl;

    return 0;
}