#include<iostream>
#include<vector>
#include<algorithm>
#define int int64_t
using namespace std;



void solve(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(auto &x:v)cin>>x;
  int count=0,start=0,end=0;
  for(int i=1;i<n;i++){
    if(v[i]<v[i-1]){
      count++;
      start=v[i-1];
      while(v[i]<v[i-1]){
        i++;
      }
      end=v[i];
    }
  }
  for(int i=start;i<end;i++){
    swap(v[i],v[end]);
    end--;
  }
  if(count==1){
    bool ans=true;
    for(int i=1;i<n;i++)if(v[i]<v[i+1])ans=false;
    if(ans)cout<<"yes"<<"\n"<<end<<" "<<start;
    else cout<<"1no";
  }
  else cout<<"no";
}

signed main(){
 //#ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    //freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    //freopen("output.txt", "w", stdout);
//	#endif
  int t=1;
  //cin>>t;
  while(t--){
   solve();
  cout<<endl;
  }
}