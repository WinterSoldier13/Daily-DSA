#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;


long long pairs(long long n){
    return (n*(n-1))/2;
}


void solve(){
    long long n,m;
    cin>>n>>m;
    long long t=n;
    long long k=m;
    int rem=n%m;
    // bool hehe=false;
    if(m==1){
        cout<<(n*(n-1))/2<<" "<<(n*(n-1))/2;
        return;
    }
    if(n==m){
      cout<<0<<" "<<0;
      return;
    }
    // vector<long long>v(m);
    // for(auto &x: v){
    //   x=n/m;
    //   n-=x;
    //   m--;
    // }
    // long long ans=0;
    // for(auto x:v)ans+=pairs(x);

  long long ans=0;
  ans+=(m-rem)*pairs(n/m);
  ans+=rem*pairs(n/m+1);



    cout<<ans<<" "<<pairs(t-k+1);
}

int main(){
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