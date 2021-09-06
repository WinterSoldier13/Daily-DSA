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



void solve(){
    int n;cin>>n;
    vi v(n);
    vin(x,v);
    int t;cin>>t;
    while(t--){
        int x,k;cin>>x>>k;
        int temp=1;
        int sum=0;
        while(true){
            if(x==n)break;
            if(v[x-1]>=k){
                v[x-1]-=k;
                k=0;
                break;
            }
            else {
                
                k-=v[x-1];
                v[x-1]=0;
            }sum+=temp*v[x];
            if(k==0)break;
            x++;
            temp++;
        }
        cout<<sum<<"\n";
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