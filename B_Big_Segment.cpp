#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include <utility>
#define int int64_t
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define vin(x,v) for(auto &x:v)cin>>x;
#define vout(x,v)for(auto x:v)cout<<x<<" ";
#define MEM(a, b) memset(a, (b), sizeof(a))
#define loop(i, j, k) for (int i=j ; i<k ; i+=1)
#define rloop(i, j, k) for (int i=j ; i>=k ; i-=1)
#define rep(i, j) loop(i, 0, j)
#define rrep(i, j) rloop(i, j, 0)
#define MP make_pair
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

void solve(){
    int n;cin>>n;
    int temp=n;
    int a,b;int ans=0;
    vector<pair<int,int>>v;
    vi aalu;
    while(n--){
        cin>>a>>b;
        v.push_back(make_pair(a,b));
        aalu.pb(a);
        aalu.push_back(b);
    }
    sort(aalu.begin(),aalu.end());
    a=aalu.front();
    b=aalu.back();
    // cout<<v[2].first<<" "<<v[2].second;
    // cout<<a<<" "<<b;
    rep(i,temp){
        if(a==v[i].first && b==v[i].second){cout<<i+1;return;}
    }
    cout<<-1;
    
}

signed main(){
ios_base::sync_with_stdio(false);cin.tie(NULL); 
 //#ifndef ONLINE_JUDGE
        //FOR GETTING INPUT FROM input.txt
        //freopen("input.txt", "r", stdin);
        //FOR GETTING INPUT FROM input.txt	
        //freopen("output.txt", "w", stdout);
//	#endif
  int t=1;
  //cin>>t;
  while(t--){
     solve();
  cout<<endl;
  }
}