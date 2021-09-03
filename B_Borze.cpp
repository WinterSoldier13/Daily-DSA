#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define int int64_t
using namespace std;



void solve(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.')cout<<0;
        else{
            if(s[i+1]=='.')cout<<1;
            else cout<<2;
            i++;
        }
    }
    
}

signed main(){
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