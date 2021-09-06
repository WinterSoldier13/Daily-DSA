#include <bits/stdc++.h>
using namespace std;
#define lli long long

int lenOfLongSubarr(int A[], int n, int k)
{
    int mxlen = 0;
    int sum = 0;

    unordered_map<int, int> hashmap;

    for (int i = 0; i < n; i++)
    {
        sum += A[i];

        if (sum == k)
        {
            mxlen = max(i + 1, mxlen);
        }
        if (hashmap.find(sum) == hashmap.end())
        {
            hashmap[sum] = i;
        }
        if(hashmap.find(sum - k) != hashmap.end())
        {
            mxlen = max(mxlen, i - hashmap[sum - k]);
        }
    }
    return mxlen;
}

int main()
{
    int A[] = {10, 5, 2, 7, 1, 9};
    int N = 6;
    int K = 15;

    cout << lenOfLongSubarr(A, N, K) << endl;
    return 0;
}
