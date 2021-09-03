#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  int n,k;
  cin>>n>>k;
  int arr[k];
  for(int i=0;i<k;i++){
  	cin>>arr[i];
  }
  sort(arr,arr+k);
  int m=INT_MAX;
  for(int i=0;i<k-n+1;i++){
  	m=min(m,arr[i+n-1]-arr[i]);
  }
  cout<<m;

}