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
    int ans=0;
    vector<pair<int,int>>v;
    rep(i,n){
        int a,b;cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    rep(i,n){
        vector<int> temp(5);
        rep(j,n){
            if(v[i].first==v[j].first && v[i].second>v[j].second)temp[1]++;

            if(v[i].first==v[j].first && v[i].second<v[j].second)temp[2]++;

            if(v[i].first<v[j].first && v[i].second==v[j].second)temp[3]++;

            if(v[i].first>v[j].first && v[i].second==v[j].second)temp[4]++;
        }
        if(temp[1]>0 && temp[2]>0 && temp[3]>0 && temp[4]>0 )ans++;
    }
    cout<<ans;
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