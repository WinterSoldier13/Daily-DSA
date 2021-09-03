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
    int n;
    int x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;
    string s;cin>>s;
    char a,b;
    if(x2>x1)a='E';else a='W';
    if(y2>y1)b='N';else b='S';
    int x=abs(x1-x2);
    int y=abs(y1-y2);
    int count=0;
    for(auto t:s){
    // cout<<x<<" "<<y<<" "<<count<<"\n";
        if(!x&!y)break;
        if(x)if(t==a)x--;
        if(y)if(t==b)y--;
        count++; 
        // cout<<x<<" "<<y;      
    }
    if(!x&!y)cout<<count;
    else cout<<-1;
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