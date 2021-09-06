#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<cstring>
#include<stack>
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
  vector<int>v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(1);
  int a=1,b=1,temp=1;
  while(temp<(int)1e9){
    temp=a+b;
    v.push_back(temp);
    a=b;
    b=temp;
  }
  vector<int>ans;
rep(i,3){
  auto it=lower_bound(v.begin(),v.end(),n);
  n-=*it;
  ans.push_back(*it);
}
if(n==0)for(auto x:ans)cout<<x<<" ";
else cout<<"I'm too stupid to solve this problem";
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