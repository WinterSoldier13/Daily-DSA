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
    vi v(8);
    rep(i,n){
        int t;cin>>t;
        v[t]++;
    }
    if(v[5] || v[7]){
        cout<<-1;
        return;
    }
    if(v[1]!=v[2]+v[3]){
        cout<<-1;
        return;
    }
    if(v[1]!=v[4]+v[6]){
        cout<<-1;
        return;
    }
    if(v[4]>v[2]){
       cout<<-1;
        return; 
    }
    if(v[2]+v[3]-v[4]!=v[6]){
        cout<<-1;
        return;
    }
    rep(i,n/3){
        cout<<1<<" ";
        if(v[3]){
            cout<<3<<" "<<6;
            v[3]--;
            v[6]--;
        }
        else{
            cout<<2<<" ";
            if(v[4]){
                cout<<4;
                v[4]--;
            }
            else cout<<6;
        }
        cout<<"\n";
    }
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