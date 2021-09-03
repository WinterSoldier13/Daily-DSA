#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

void solve(vector<int> arr, int k)
{
    deque<int> dq;
    vector<int> out;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (!dq.empty())
        out.push_back(arr[dq.front()]);
    else
    {
        out.push_back(0);
    }

    for (int i = k; i < arr.size(); i++)
    {
        if(!dq.empty() and i-dq.front()>=k)
        dq.pop_front();
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        if (!dq.empty())
            out.push_back(arr[dq.front()]);
        else
        {
            out.push_back(0);
        }
    }
    for (auto x : out)
        cout << x << " ";
    cout << endl;
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        solve(arr, k);
    }
    return 0;
}