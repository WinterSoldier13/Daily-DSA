#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


long long minno(long long n, long long k){
  if(k==1)return 1+minno(n,k+1);
  if(n==0||k>n){
    return 1;
  }
  return 1+min(minno(n/k,k),minno(n,k+1));
  
}


void solve(){
    long long n,k;
    cin>>n>>k;
    cout<<minno(n,k);
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