#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<cstring>
#include<string>
#include<math.h>
#include <utility>
#define int int64_t
//typedef vector<int> vi;
//typedef vector<string> vs;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define rep(i, j) FOR(i, 0, j, 1)
#define rrep(i, j) RFOR(i, j, 0, 1)
#define MP make_pair
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;



void solve(){
    vector<int>v(3),sq(3);
    for(auto &x:v)cin>>x;
    int z=v[0]*v[1]*v[2];
    rep(i,3)sq[i]=z/(v[i]*v[i]);
    for(auto &x:sq)x=pow(x,0.5);
    int ans=0;
    for(auto x:sq)ans+=x;
    cout<<ans*4;

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