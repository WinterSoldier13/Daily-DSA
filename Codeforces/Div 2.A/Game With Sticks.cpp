#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  int m,n;
  cin>>m>>n;
  int ans=0;
  while(m*n!=0){
  	m--;
  	n--;
  	ans++;
  }
  if(ans%2!=0) cout<<"Akshat";
  else cout<<"Malvika";
}