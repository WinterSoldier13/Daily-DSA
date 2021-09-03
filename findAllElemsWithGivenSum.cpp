#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

void printResult(vector<pair<int, int>> &out)
{
    int l = out.size();
    if(l == 0)
    {
        cout<<"-1"<<endl;
        return;
    }
    for(int i=0;i<l;i++)
    {
        cout<<out[i].first<<" "<<out[i].second;
        if(i!=l-1)
        {
            cout<<", ";
        }
    }
    cout<<endl;
}
void solve(vector<int> &arr1, vector<int> &arr2, int x)
{
    int n = arr1.size();
    int m = arr2.size();

    sort(arr1.begin(), arr1.end());
    // sort(arr2.begin(), arr2.end());
    
    unordered_set<int> hash1;
    unordered_set<int> hash2;

    // for(auto x: arr1)
    // hash1.insert(x);
    for(auto x: arr2)
    hash2.insert(x);


    vector<pair<int, int>> out;

    for (int i = 0; i < n; i++)
    {
        if(hash2.find(x - arr1[i]) != hash2.end())
        {
            out.push_back(make_pair(arr1[i], x - arr1[i]));
        }
    }

    // sort(out.begin(), out.end());
    printResult(out);
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
        int n, m, x;
        cin >> n >> m >> x;

        vector<int> arr1(n);
        vector<int> arr2(m);

        for (int i = 0; i < n; i++)
            cin >> arr1[i];

        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        solve(arr1, arr2, x);
    }

    return 1;
}