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
#define vii vector<pair<int,int>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define mp make_pair
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



void solve(){
    int n,l,r,s;cin>>n>>l>>r>>s;
    int ts=s;
    vi v(n+1,1);

    vi ans;
    vi lr,sm;
    int t=0;
    loop(i,1,n+1){
        t+=i;
        sm.pb(t);
    }
    t=0;
    for(int i=n;i>0;i--){
        t+=i;
        lr.pb(t);
    }

    if(lr[r-l]<s){
        cout<<-1;return;
    }

    if(sm[r-l]>s){
        cout<<-1;return;
    }
    

    t=r-l;
    int z=1;
    while(t>=0){
        if(z==n+1)break;
        if(s-z>=sm[t] && s-z<=lr[t]){
            ans.pb(z);
            t--;
            s-=z;
        }
        z++;
    }
    int sum=0;
    for(auto x:ans){
        sum+=x;
        sum+=1;
    }
    if(sum==ts){vout(x,ans);}
    else cout<<-1;
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
  cin>>t;
  while(t--){
     solve();
  cout<<endl;
  }
}