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

vector<int> lucky;

void luckyno(int n){
    if(n>(int)1e9+10)return;
    lucky.pb(n*10+4);
    lucky.pb(n*10+7);
    luckyno(n*10+4);
    luckyno(n*10+7);
    
}


void solve(){
    int l,r;cin>>l>>r;
    luckyno(0);
    sort(lucky.begin(),lucky.end(),greater<int>());
    // vout(x,lucky);
    int sum=0;
    loop(i,l,r+1){
        while(lucky.back()<i)lucky.pop_back();
        if(lucky.back()<=r){
            sum+=(lucky.back()*(lucky.back()-i))+lucky.back();
            i=lucky.back()+1;
        }
        else{ sum+=lucky.back()*(r-i+1);
        i=r+5;}
        i--;
    }
    cout<<sum;
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