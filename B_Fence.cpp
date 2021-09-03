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

int v[(int)1e6];


void solve(){
    int n,m;
    cin>>n>>m;
    rep(i,n){
        int t;cin>>t;
        v[i]=t;
    }
    
    // v.push_back(MOD);
    // v.push_back(MOD);
    // v.push_back(MOD);
    // v.push_back(MOD);
    // v.push_back(MOD);
    // v.push_back(MOD);
    loop(i,n,n+5){
        v[i]=MOD;
    }


    int index=0;
    int ans=0;
    rep(i,m)ans+=v[i];
    rep(i,n-m+1){
        if(m==1 && v[i]==1){
            cout<<i+1;
            return;
        } 
        // if(i==0)continue;
        int temp=ans;
        if(ans>ans+v[i+m-1]-v[i-1])ans=ans+v[i+m-1]-v[i-1];
        if(ans!=temp)index=i;
    }
    cout<<index+1;
    
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