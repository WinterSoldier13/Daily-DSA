#include <bits/stdc++.h>
using namespace std;

// void print(vector<bool> arr)
// {
//     for (auto x : arr)
//         cout << x << " ";
//     cout << endl;
// }

// See Nick White Video

int oddEvenJumps(vector<int> &a)
{
    int n = a.size();

    // For the last element, the answer should atleast be 1
    int jumps = 1;

    // Defining two arrays for dp
    // arr[i] stores whether it is possible to reach the end if current iteration is the even or odd resp.
    vector<bool> low(a.size());
    vector<bool> high(a.size());

    // FOr the last it is always true
    low[n - 1] = 1, high[n - 1] = 1;

    map<int, int> m;
    m.insert({a[n - 1], n - 1});

    for (int i = n - 2; i >= 0; i--)
    {
        if (m.find(a[i]) != m.end())
        {
            auto it = m.find(a[i]);
            low[i] = high[it->second];
            high[i] = low[it->second];
        }
        else
        {
            auto it = m.upper_bound(a[i]);
            if (it != m.end())
                high[i] = low[it->second];
            else
                high[i] = false;
            it = m.lower_bound(a[i]);
            if (it == m.begin())
                low[i] = false;
            else
                low[i] = high[(--it)->second];
        }
        m[a[i]] = i;
        if (high[i])
            jumps++;
    }
    return jumps;
}

int main()
{
    vector<int> arr{10, 13, 12, 14, 15};

    cout << oddEvenJumps(arr) << endl;
}