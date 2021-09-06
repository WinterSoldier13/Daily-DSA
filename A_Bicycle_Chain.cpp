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
    int z=0;
    int mx=INT64_MIN,count=0;
    int n;cin>>n;vector<int>v1(n);
    for(auto &x:v1)cin>>x;
    int m;cin>>m;vector<int>v2(m);
    for(auto &x:v2)cin>>x;
    for(auto x1:v1){
        for(auto x2:v2){
            if(x1!=0){
                double temp=x2/x1;
                // cout<<temp<<" ";
                if(temp-(int)temp==0){
                    // cout<<"..  ";
                    if(temp==mx)count++;
                    else {
                        mx=max(mx,(int)temp);
                        count=1;
                    }
                }
            }
        }
    }
    cout<<count;
    
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