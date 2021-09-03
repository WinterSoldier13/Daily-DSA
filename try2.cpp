#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void solve(){
  cout<<"Hello";
}

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  int t=1;
  //cin>>t;
  while(t--){
   solve();
   cout<<"\n";
  }
}