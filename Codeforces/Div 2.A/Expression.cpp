#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  int a,b,c;
  cin>>a>>b>>c;
 
// a+b+c
// a+b*c
// a*b+c
// a*b*c
// (a+b)*c
// a*(b+c)


cout<<max(max(max(a+b+c,a+b*c),max(a*b*c,a*b+c)), max((a+b)*c,a*(b+c))

}