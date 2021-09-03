#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    int i,val;
    set<int> a;
    cin>>i;
    for(int z=0;z<i;z++){
        cin>>val;
        a.insert(val);
    }
    cin>>i;
    for(int z=0;z<i;z++){
        cin>>val;
        a.insert(val);
    }
    if(a.size()==n)cout<<"I become the guy.";
    else cout<<"Oh, my keyboard!";

}

int main(){
  //#ifndef ONLINE_JUDGE
        //FOR GETTING INPUT FROM input.txt
        //freopen("input.txt", "r", stdin);
        //FOR GETTING INPUT FROM input.txt	
        //freopen("output.txt", "w", stdout);
    //#endif
  int t=1;
  //cin>>t;
  while(t--){
     solve();
  }
}