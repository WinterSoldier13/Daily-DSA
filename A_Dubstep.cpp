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
    string s;
    cin>>s;
    vector<char>ans;
    bool start=false;
    rep(i,s.size()){
        if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B'){i+=2;ans.push_back(' ');}
        else{ ans.push_back(s[i]);}
    }
    for(int i=0;i<ans.size();i++){
        if(ans[i]==' ' && ans[i+1]==' ')i++;
        cout<<ans[i];
    }


        // if(ans.size()==0){
        //     if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B'){i+=2;ans.push_back('^');}
        //     continue;
        // }
        // if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B'){i+=2;ans.push_back(' ');}
        // else{ ans.push_back(s[i]);}
    
   
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