#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (auto &x : v)
        cin >> x;
    int a = 1;
    long long ans = 0;
    while (v.size())
    {
        // if(a==n+1)a=1;
        // if(a==v[0]){
        //      v.erase(v.begin(),v.begin()+1);
        //      a--;
        //      ans--;
        // }
        // ans++;
        // a++;

        if (a > v[0])
            ans += n - (a - v[0]);
        else
            ans += v[0] - a;
        a = v[0];
        v.erase(v.begin(), v.begin() + 1);
    }
    cout << ans;
}

int main()
{
    //#ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    //freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt
    //freopen("output.txt", "w", stdout);
    //	#endif
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}