#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void solve(){
  long long n;
  cin>>n;
  if(n<3){
      cout<<0;
      return;
  }
  vector<long long> v(n);
  for(auto &x: v)cin>>x;
  vector<long long> v1,v2,v3;
  for(long long i=0;i<n;i++){
      if(v[i]==1)v1.push_back(i+1);
      if(v[i]==2)v2.push_back(i+1);
      if(v[i]==3)v3.push_back(i+1);
  }
  long long z=min(v1.size(),(v2.size(),v3.size()));
  cout<<z<<"\n";
  for(long long i=0;i<z;i++){
      cout<<v1[i]<<" ";
      cout<<v2[i]<<" ";
      cout<<v3[i]<<" ";
      cout<<"\n";
  }
}

int main(){
//   #ifndef ONLINE_JUDGE
//         //FOR GETTING INPUT FROM input.txt
//         freopen("input.txt", "r", stdin);
//         //FOR GETTING INPUT FROM input.txt	
//         freopen("output.txt", "w", stdout);
//     #endif
  long long t=1;
  //cin>>t;
  while(t--){
     solve();
  }
}