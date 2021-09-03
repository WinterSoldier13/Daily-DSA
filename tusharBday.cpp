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

vector<int> solve(int res, vector<int> &arr)
{

    int n = arr.size();
    int min_strength = INT_MAX;
    vector<int> ans;

    int minVal = *min_element(arr.begin(), arr.end());
    int maxHitsPossible = res / minVal;
    int totalStrengthApplied = maxHitsPossible * minVal;
    // cout << "TotalStr " << totalStrengthApplied << endl;

    // now I need to give the lexogrphiclly smallest ans
    // my answer length should be = maxHitsPossible, as in the question they have given :
    // "lexicographically smallest array of maximum length"
    // so to satisfy the second condition of maximumLength my ans.size() == maxHitsPossible

    // to find the lexographically smallest answer, I will iterate from the 0th index and check if it is possible to
    // use the value of this index in my answer or not

    int i = 0;
    while (i < n)
    {
        int currVal = arr[i];

        // to check if it is possible to use this value or not, I need to replace one of the 'maxHitsPossible' 'minVal' with my currentVal
        // if my currentVal still satisfies the condition I will prefer to use it over one of the 'minVal'
        cout<<i<<endl;
        while ((totalStrengthApplied - minVal + currVal) <= res and maxHitsPossible--)
        {
            // cout<<"stuck in loop"<<endl;
            ans.push_back(i);
            totalStrengthApplied = totalStrengthApplied - minVal + currVal;
        }
        i++;
    }

    return ans;
}

int main()
{
    // fast_cin();

    int res = 11;
    vector<int> arr{6, 8, 5, 4, 7};

    // cout<<"hello"<<endl;
    auto ans = solve(res, arr);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}