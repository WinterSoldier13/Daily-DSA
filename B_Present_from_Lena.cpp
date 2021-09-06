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
    for(int i=0;i<n+1;i++){
      for(int j=i;j<n;j++)cout<<"  ";
      for(int j=0;j<i;j++)cout<<j<<" ";
      cout<<i;if(i!=0)cout<<" ";
      for(int j=i-1;j>=0;j--){cout<<j;if(j!=0)cout<<" ";}
      cout<<"\n";
    }
    for(int i=1;i<=n;i++){
      for(int j=0;j<i;j++)cout<<"  ";
      for(int j=0;j<n-i;j++)cout<<j<<" ";
      cout<<n-i;if(n-i!=0)cout<<" ";
      for(int j=n-i-1;j>=0;j--){cout<<j;if(j!=0)cout<<" ";}
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