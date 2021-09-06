
//This soln is by DFS scroll Down to see the solution by DSU


// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<stack>
// #include<map>
// #include<set>
// #include<stack>
// #include<queue>
// #include<cstring>
// #include<string>
// #include <utility>
// #define int int64_t
// #define vi vector<int>
// #define vii vector<pair<int,int>>
// #define vs vector<string>
// #define vc vector<char>
// #define vb vector<bool>
// #define pb push_back
// #define mp make_pair
// #define vin(x,v) for(auto &x:v)cin>>x;
// #define vout(x,v)for(auto x:v)cout<<x<<" ";
// #define MEM(a, b) memset(a, (b), sizeof(a))
// #define loop(i, j, k) for (int i=j ; i<k ; i+=1)
// #define rloop(i, j, k) for (int i=j ; i>=k ; i-=1)
// #define rep(i, j) loop(i, 0, j)
// #define rrep(i, j) rloop(i, j, 0)
// #define MP make_pair
// #define INF (int)1e18
// #define EPS 1e-18
// #define PI 3.1415926535897932384626433832795
// #define MOD 1000000007
// using namespace std;

// vi graph[27];
// vb visited(27,false);

// void dfs(vi node, int n){
//     visited[n]=true;
//     for(auto x:node){
//         if(visited[x])continue;
//         dfs(graph[x],x);
//     }
// }


// void solve(){
//     int n;cin>>n;
    
//     rep(i,n){
//         string s;cin>>s;
//         if(s.size()==1){
//             graph[s[0]-'a'].push_back(s[0]-'a');
//             continue;}
//         rep(i,s.size()-1){
//             graph[s[i]-'a'].push_back(s[i+1]-'a');
//             graph[s[i+1]-'a'].push_back(s[i]-'a');           
//         }
//     }

//     int ans=0;
//     loop(i,0,27){
//         if(!visited[i] && graph[i].size()!=0){dfs(graph[i],i);ans++;}
//     }
//     cout<<ans;

// }

// signed main(){
// ios_base::sync_with_stdio(false);cin.tie(NULL); 
//  //#ifndef ONLINE_JUDGE
//         //FOR GETTING INPUT FROM input.txt
//         //freopen("input.txt", "r", stdin);
//         //FOR GETTING INPUT FROM input.txt	
//         //freopen("output.txt", "w", stdout);
// //	#endif
//   int t=1;
//   //cin>>t;
//   while(t--){
//      solve();
//   cout<<endl;
//   }
// }



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


vector<vector<int>> graph(10010);
vb visited((int)1e5+10,false);


void solve(){
    int n;cin>>n;cout<<graph.size()<<" ";
    graph.resize(0);
    cout<<graph.size();

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