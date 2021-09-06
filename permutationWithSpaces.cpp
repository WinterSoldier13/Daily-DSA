#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

void recurse(vector<char> &arr, int index, vector<char> temp, vector<vector<char>> &mothership)
{
    if (index == arr.size())
    {
        mothership.push_back(temp);
        return;
    }

    temp.push_back(arr[index]);
    recurse(arr, index + 1, temp, mothership);
    temp.pop_back();

    temp.push_back(' ');
    temp.push_back(arr[index]);
    recurse(arr, index + 1, temp, mothership);
    temp.pop_back();
    temp.pop_back();
}

void solve(string s)
{
    int l = s.size();

    vector<char> arr{s[0]};
    for (int i = 1; i < l; i++)
    {
        arr.push_back(s[i]);
    }

    vector<char> temp{s[0]};

    vector<vector<char>> mothership;

    recurse(arr, 1, temp, mothership);
    set<string> hashset;

    for (auto x : mothership)
    {
        string t  = "";
        for (auto c : x)
        {
            t+=c;
        }
        hashset.insert(t);
    }

    for(auto it = hashset.begin();it!=hashset.end();it++)
    {
        cout<<"("<<*it<<")";
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
        string s;
        cin >> s;

        solve(s);
    }

    return 0;
}