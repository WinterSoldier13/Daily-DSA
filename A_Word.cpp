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
    string s;
    cin>>s;
    int u,l;u=l=0;
    int t;
    for(auto x:s){
        t=x;
        if(x<95)u++;
        else l++;
    }
    if(u>l)transform(s.begin(), s.end(), s.begin(), ::toupper); 
    else transform(s.begin(), s.end(), s.begin(), ::tolower); 
    cout<<s;
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