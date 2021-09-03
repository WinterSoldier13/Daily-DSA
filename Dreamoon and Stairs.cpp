#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void solve(){
    int n,k;
    cin>>n>>k;
    if(k>n)cout<<-1;
    else if(n==k)cout<<n;
    else{
        if(n%2==1)n++;
        int t= n/2;
        while(t%k!=0){
            t++;
        }
        cout<<t;
    }
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
  }
}