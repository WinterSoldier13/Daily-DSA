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
    int a,b,c,d;
    string s;
    cin>>s;
    a=s.length();
    cin>>s;
    b=s.length();
    cin>>s;
    c=s.length();
    cin>>s;
    d=s.length();
    a-=2;
    b-=2;
    c-=2;d-=2;
    
    if(a>=2*b && a>=2*c && a>=2*d)cout<<"A";
    else if(a<=2*b && a<=2*d && a<=2*c)cout<<"A";
    
    else if(b>=2*a && b>=2*c && b>=2*d)cout<<"B";
    else if(b<=2*a && b<=2*d && b<=2*c)cout<<"B";
    
    else if(c>=2*b && c>=2*a && c>=2*d)cout<<"C";
    else if(c<=2*b && c<=2*a && c<=2*d)cout<<"C";
    
    else if(d>=2*b && d>=2*c && d>=2*a)cout<<"D";
    else if(d<=2*a && d<=2*b && d<=2*c)cout<<"D";
    
    else cout<<"C";
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