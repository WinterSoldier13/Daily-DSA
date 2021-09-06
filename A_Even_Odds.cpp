#include<iostream>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt    
    freopen("output.txt", "w", stdout);
  #endif
  int t;
  t=1;
  while(t){
   long long n,x;
   cin>>n>>x;
   if((2*x)-1<=n)cout<<(2*x)-1;
   else cout<<(x-((n+1)/2))*2;
  t--;
  }
}