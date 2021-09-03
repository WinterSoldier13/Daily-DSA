#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

void solve(vector<int> arr1, vector<int> arr2)
{
    int l1 = arr1.size();
    int l2 = arr2.size();

    unordered_map<int, int> hashmap;
    for (auto x : arr1)
    {
        hashmap[x]++;
    }

    vector<int> out;

    for (auto x : arr2)
    {
        for (int i = 0; i < hashmap[x]; i++)
        {
            out.push_back(x);
        }
        hashmap.erase(hashmap.find(x));
    }

    vector<int> temp;
    for (auto it = hashmap.begin(); it != hashmap.end(); it++)
    {
        for (int i = 0; i < it->second; i++)
        {
            temp.push_back(it->first);
        }
    }
    sort(temp.begin(), temp.end());

    for (auto x : temp)
        out.push_back(x);

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
        int n, m;
        cin>>n>>m;

        vector<int> arr1(n);
        vector<int> arr2(m);

        for(int i=0;i<n;i++)
        cin>>arr1[i];
        for(int i=0;i<m;i++)
        cin>>arr2[i];

        solve(arr1, arr2);
    }
    return 1;
}