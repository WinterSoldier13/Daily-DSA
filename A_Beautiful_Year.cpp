#include<iostream>
#include<vector>
#include<algorithm>
#define int int64_t
using namespace std;


bool soln(int n){
    int a,b,c,d;
    a=n%10;
    n=n/10;b=n%10;
    n=n/10;c=n%10;
    n=n/10;d=n%10;
    if(a!=b&&a!=c&&a!=d){
        if(b!=c&&b!=d){
            if(c!=d)return true;
        }
    }
    return false;
}


void solve(){
    int n;
    cin>>n;
    for(int i=n+1;i<10000;i++){
        if(soln(i)){
            cout<<i;
            break;
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