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

vector<pair<int,int>> graph[(int)1e5+10];
vector<bool> visited((int)1e5+10,false);
int ans=0;
vi v((int)1e5+10);






void dfs(vii node){
    if(node.size()==1){
        for(auto &x:v){
            if(x>=0){ans++;x=INT32_MIN;}
        }
        return;
    }
    for(auto x:node){
            if(!visited[x.first]){
                for(auto &z:v)z-=x.second;
            visited[x.first]=true;           
            dfs(graph[x.first]);
            for(auto &z:v)z+=x.second;
        }
    }
}



void solve(){
    int n,m;cin>>n>>m;
    rep(i,n+1){
        graph[i].clear();
        visited[i]=false;
        v[i]=0;
        ans=0;
    }   
    rep(i,m){
        int t;cin>>t;v.push_back(t);
    }
    rep(i,n-1){
        int a,b,t;
        cin>>a>>b>>t;
        graph[a].push_back(MP(b,t));
        graph[b].push_back(MP(a,t));       
    }
        graph[1].push_back(MP((int)1e5+7,0));
        dfs(graph[1]);
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
  cin>>t;
  while(t--){
     solve();
  cout<<endl;
  }
}