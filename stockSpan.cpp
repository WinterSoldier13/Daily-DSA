#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

void solve(vector<int> &arr)
{
    int l = arr.size();
    vector<int> out(l);
    out[0] = 1;
    for(int i=1;i<l;i++)
    {
        int count = 1;
        for(int j = i-1;j>=0;j--)
        {
            if(arr[j]>arr[i])
            {
                break;
            }
            count++;
        }
        out[i] = count;
    }
    for(auto x: out)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        solve(arr);
    }
}