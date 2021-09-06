#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt  
    freopen("output.txt", "w", stdout);
  #endif
  string a,b;
  cin>>a>>b;
  transform(a.begin(),a.end(),a.begin(),::tolower);
  transform(b.begin(),b.end(),b.begin(),::tolower);
  if(a>b) cout<<1;
  else if(b>a)  cout<<-1;
  else cout<<0;
  }
