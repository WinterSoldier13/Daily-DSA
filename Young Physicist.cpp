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
  int a[n],b[n],c[n];
  for(int i=0;i<n;i++){
  	cin>>a[i]>>b[i]>>c[i];
  }
  int asum=0,bsum=0,csum=0;
  for(int i=0;i<n;i++){
  	asum+=a[i];
  	bsum+=b[i];
  	csum+=c[i];
  }
 // cout<<asum<<bsum<<csum<<"\t";
  if(asum==0 && bsum==0 && csum==0) cout<<"YES";
  else cout<<"NO";
}