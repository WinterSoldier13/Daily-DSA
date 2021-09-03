#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void solve(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=0;i<20;i++){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<arr[a-1]<<" "<<arr[b-1]<<" "<<arr[c-1]<<"\n";
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
   cout<<"\n";
  }
}