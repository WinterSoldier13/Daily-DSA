#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  int s,n;
  cin>>s>>n;
  vector<int,int> v;
  int a,b;
  for(int i=0;i<n;i++){
  	cin>>a>>b;
  	v.push_back(a,b);
  }
  for(auto x:v)cout<<x;
}