#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  int t=1;
  //cin>>t;
  while(t){
   int n;
   cin>>n;
   if(n>=0)cout<<n;
   else{
   	cout<<max(n/10,((n/100)*10)+n%10);
   }
  t--;
  }
}