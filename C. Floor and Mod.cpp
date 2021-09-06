#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void solve(){
  int x,y;
  int ans=0;
  cin>>x>>y;
  for(int i=1;i<=x;i++){
  	for(int j=1;j<=i;j++){
  		if(i/j==i%j)ans++;
  	}
  }
  cout<<ans;
}

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  int t=1;
  cin>>t;
  while(t--){
   solve();
   cout<<"\n";
  }
}