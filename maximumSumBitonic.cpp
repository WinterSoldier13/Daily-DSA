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

// https://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence/0/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&problemStatus=unsolved&difficulty[]=0&page=1&query=category[]Dynamic%20ProgrammingproblemStatusunsolveddifficulty[]0page1category[]Dynamic%20Programminghttps://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence/0/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&problemStatus=unsolved&difficulty[]=0&page=1&query=category[]Dynamic%20ProgrammingproblemStatusunsolveddifficulty[]0page1category[]Dynamic%20Programming

void solve(vector<int> arr)
{
    int l = arr.size();

    vector<int> increasing(l, 0);
    vector<int> decreasing(l, 0);

    increasing[0] = arr[0];

    for (int i = 1; i < l; i++)
    {
        increasing[i] = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                increasing[i] = max(increasing[i], arr[i] + increasing[j]);
            }
        }
    }


    reverse(arr.begin(), arr.end());
    decreasing[0] = arr[0];

    for (int i = 1; i < l; i++)
    {
        decreasing[i] = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                decreasing[i] = max(decreasing[i], arr[i] + decreasing[j]);
            }
        }
    }
    reverse(decreasing.begin(), decreasing.end());
    reverse(arr.begin(), arr.end());


    int max_ = INT_MIN;

    for (int i = 0; i < l; i++)
    {
        max_ = max(max_, increasing[i] + decreasing[i] - arr[i]);
    }

    for (auto x : arr)
        cout << x <<" ";
    cout << endl;
    for (auto x : increasing)
        cout << x << " ";

    cout << endl;
    for (auto x : decreasing)
        cout << x << " ";
    cout << endl;

    cout << max_ << endl;
}

int main()
{
    fast_cin();

    // getT()
    // {
    //     int n;
    //     cin >> n;
    //     vector<int> arr(n);

    //     for (int i = 0; i < n; i++)
    //     {
    //         cin >> arr[i];
    //     }
    //     solve(arr);
    // }

    // vector<int> arr{107 ,13 ,10 ,62 ,3 ,68 ,51, 20 ,84 ,47, 61, 67 ,53 ,17 ,12, 9};
    vector<int> arr{70 ,63 ,51 ,63 ,44 ,68 ,56 ,90};
    solve(arr);
    return 0;
}