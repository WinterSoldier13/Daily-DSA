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

vi decToBinary(int n)
{
    vi binaryNum;
    int i = 0;
    while (n > 0) {
        binaryNum.pb( n% 2);
        n = n / 2;
        i++;
    }
    return binaryNum;
}


void solve(){
    // vi a,b,c,d;
    // a=decToBinary(8);
    // b=decToBinary(5);
    // c=decToBinary(111);
    // d=decToBinary(17);
    
    // vout(x,a);
    // cout<<"\n";
    // vout(x,b);
    // cout<<"\n";
    // vout(x,c);
    // cout<<"\n";
    // vout(x,d);
    // cout<<"\n";
    // return;


    int n,m,k;
    cin>>n>>m>>k;
    vi v(m+1);
    vin(x,v);
    vi vans=decToBinary(v[m]);
    // vout(x,vans);return;
    int ans=0;
    rep(i,m){
        int temp=0;
        vi vt=decToBinary(v[i]);
        rep(i,vans.size()){
            if(vans[i]!=vt[i])temp++;
            cout<<vans[i]<<" "<<vt[i]<<" "<<temp<<"\n";
        }
        if(temp<=k)ans++;
        cout<<"\n";
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