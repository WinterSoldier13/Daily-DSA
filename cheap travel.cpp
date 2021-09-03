#include<bits/stdc++.h>
using namespace std;



void solve(){
  int n, m, a,b, cost=0;
    cin>>n>>m>>a>>b;
    if((a*m)>b){
        int r=n/m;
        cost+=r*b;
        r=n-m*r;
        if(r*a>b)
           cost+= b;
        else
           cost+=r*a;
    }
    else
        cost+=a*n;
        
        
    cout<<cost;  
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
  while(t){
   solve();
  t--;
  }
}