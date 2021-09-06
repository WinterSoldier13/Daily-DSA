#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  int n;
  cin>>n;
  bool ans=false;
  int arr[]={4,7,44,47,77,444,447,474,477,744,747,777};
  for(auto x:arr){
  	if(n>=x){
  		if(n%x==0){
  			ans=true;
  			break;
  		}
  	}
  }
  if(ans==true) cout<<"YES";
  else cout<<"NO";
}