#include <bits/stdc++.h>
using namespace std;

void solve()
{
   // cout<<"hello";
    long long int n, k;
    cin >> n >> k;
    long long int ans=-1;
    for(long long int i=1;i<=n;i+=2){
        k--;
        ans=i;
        if(k==0){
            cout<<ans;
            break;
        }
    }
    ans=0;
    if(k>0){
    for(long long int i=2;i<=n;i+=2){
        k--;
        ans=i;
        if(k==0){
            cout<<ans;
            break;
        }
    }
    }
    
    //cout<<a[k-1];
}

int main()
{
    //#ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    //freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt
    //freopen("output.txt", "w", stdout);
    //#endif
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
}