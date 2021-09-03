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
    int n;cin>>n;
    vi a,b,c;
    vi v(n);
    vin(x,v);
    for(auto x:v){
        if(x<0)a.pb(x);
        else if(x>0)b.pb(x);
        else c.push_back(x);
    }

    if(a.size()%2==0){
        c.pb(a.back());
        a.pop_back();
    }
    if(b.size()==0){
        b.push_back(a.back());
        a.pop_back();
        b.push_back(a.back());
        a.pop_back();
    }


    cout<<a.size()<<" ";
    vout(x,a);
    cout<<"\n";
    cout<<b.size()<<" ";
    vout(x,b);
    cout<<"\n";
    cout<<c.size()<<" ";
    vout(x,c);
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