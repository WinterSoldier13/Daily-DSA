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
#define vvi vector<vector<int>>
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

vi graph[101];
vb visited(101);


void dfs(vi node, int n){
    visited[n]=true;
    for(auto x:node){
        if(!visited[x])dfs(graph[x],x);
    }
}


void solve(){
    int ans=0;
    int n,m;cin>>n>>m;
    rep(i,n){
        int t;cin>>t;
        if(t==0){
            ans++;
            continue;
        }
        int temp;
        cin>>temp;
        if(t==1){
            graph[temp].push_back(temp);
            // cout<<"f";
            continue;
        }
        rep(i,t-1){
            int z;cin>>z;
            graph[temp].push_back(z);
            // cout<<"f";
            graph[z].push_back(temp);
        }
    }
    bool check=true;
    rep(i,101){
        if(graph[i].size())check=false;
    }
    if(check){cout<<ans;return;}

    for(int i=0;i<=100;i++){
        if(!graph[i].size())continue;
        if(!visited[i])dfs(graph[i],i), ans++;
    }
    // vout(x,graph[0]);
    cout<<ans-1;
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