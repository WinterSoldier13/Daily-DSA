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

bool check(int arr[3][3]){
    int t=arr[0][0]+arr[0][1]+arr[0][2];
    bool ans=true;
    if(arr[0][0]+arr[0][1]+arr[0][2]!=t)ans=false;
    if(arr[1][0]+arr[1][1]+arr[1][2]!=t)ans=false;
    if(arr[2][0]+arr[2][1]+arr[2][2]!=t)ans=false;
    if(arr[0][0]+arr[1][0]+arr[2][0]!=t)ans=false;
    if(arr[1][0]+arr[1][1]+arr[1][2]!=t)ans=false;
    if(arr[2][0]+arr[2][1]+arr[2][2]!=t)ans=false;
    if(arr[0][0]+arr[2][2]+arr[1][1]!=t)ans=false;
    if(arr[2][0]+arr[1][1]+arr[0][2]!=t)ans=false;
    return ans;
}

void solve(){
    int arr[3][3];
    rep(i,3){
        rep(j,3){
            cin>>arr[i][j];
        }
    }
    rep(i,(int)1e5+1){
        arr[0][0]=i;
        arr[1][1]=arr[0][2]+i-arr[2][1];
        arr[2][2]=arr[0][1]+i-arr[1][2];
        if(check(arr)){
            rep(i,3){
                rep(j,3)cout<<arr[i][j]<<" ";
                cout<<"\n";
            }
            return;
        }
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