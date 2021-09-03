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
    set<string>st;
    string f,m,s;
    cin>>f>>m>>s;
    st.insert(f);
    st.insert(m);
    st.insert(s);
    if(st.size()==1 || st.size()==3){cout<<"?";return;}
    
    bool check=false;


    if(f=="rock"){
      if(m=="scissors" && s=="scissors"){cout<<"F";check=true;}
    }

    if(f=="paper"){
      if(m=="rock" && s=="rock"){cout<<"F";check=true;}
    }


    if(f=="scissors"){
      if(m=="paper" && s=="paper"){cout<<"F";check=true;}
    }

//-----------------------------------------------------------------------------//

    if(m=="rock"){
      if(f=="scissors" && s=="scissors"){cout<<"M";check=true;}
    }

    if(m=="paper"){
      if(f=="rock" && s=="rock"){cout<<"M";check=true;}
    }


    if(m=="scissors"){
      if(f=="paper" && s=="paper"){cout<<"M";check=true;}
    }




    //-----------------------------------------------------------------------------//

    if(s=="rock"){
      if(f=="scissors" && m=="scissors"){cout<<"S";check=true;}
    }

    if(s=="paper"){
      if(f=="rock" && m=="rock"){cout<<"S";check=true;}
    }


    if(s=="scissors"){
      if(f=="paper" && m=="paper"){cout<<"S";check=true;}
    }
    
    if(!check)cout<<"?";
    
    
    
    
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