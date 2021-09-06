#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli unsigned long long int

int keyPair(vector<int> &arr, int num)
{
    int n = arr.size();

    unordered_set<int> hashset;

    for (auto x : arr)
    {
        int req = num - x;
        if (hashset.count(req))
        {
            return 1;
        }
        hashset.insert(x);
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (keyPair(arr, x))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}