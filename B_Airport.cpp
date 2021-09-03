#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<cstring>
#include<string>
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
    int n;cin>>n;
    int m;cin>>m;
    vector<int>v(m);
    for(auto &x:v)cin>>x;
    sort(v.begin(),v.end());
    vector<int> temp=v;
    int a=0,b=0;
    rep(i,n){
        a+=temp.front();
        temp.front()--;
        if(temp.front()==0)temp.erase(temp.begin());
    }
    temp=v;
    int z=0;
    int index=0;
    rep(i,n){
        for(int j=0;j<m;j++){
            b=max(b,v[j]);
            if(b==v[j])index=j;
        }
        z+=b;
        b=0;     // for(auto x:v)cout<<x<<" ";
        v[index]--;
    }
    cout<<z<<" "<<a;


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