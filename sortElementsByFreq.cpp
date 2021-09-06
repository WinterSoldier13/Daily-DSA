#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

class customCom
{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.first > p2.first)
        {
            return 0;
        }
        else if (p1.first == p2.first)
        {
            return p1.second > p2.second;
        }
        else
        {
            return 1;
        }
    }
};

void solve(vector<int> &arr)
{
    unordered_map<int, int> hashmap;

    for (auto x : arr)
    {
        hashmap[x]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, customCom> pq;

    for (auto it = hashmap.begin();it!=hashmap.end();it++)
    {
        pq.push(make_pair(hashmap[it->first], it->first));
    }

    while(!pq.empty())
    {
        auto top_ = pq.top();
        pq.pop();
        // cout<<top_.first<<" "<<top_.second<<endl;
        for(int i=0;i<hashmap[top_.second];i++)
        {
            cout<<top_.second<<" ";
        }
    }
    cout<<endl;
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
        solve(arr);
    }
    return 1;
}