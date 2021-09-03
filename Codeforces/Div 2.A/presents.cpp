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
  int arr1[n];
  for(int i=0;i<n;i++){
  	cin>>arr1[i];
  }
  int arr2[n]={0};
  for(int i=0;i<n;i++){
  	arr2[arr1[i]-1]=i+1;
  }
  for(auto x:arr2) cout<<x<<"\t";
}