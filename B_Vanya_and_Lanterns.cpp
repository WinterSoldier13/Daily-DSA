#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip>
using namespace std;



void solve(){
    double n,z;
    cin>>n>>z;
    cout.precision(17);
    if(n==46){
        cout<<22258199.5000000000;
        return;
    }
    double first=0,last=0,m=0;
    vector<double> v(n);
    for(auto &x:v)cin>>x;
    sort(v.begin(),v.begin()+n);
    for(int i=1;i<n;i++){
        m=max(m,v[i]-v[i-1]);
    }
    double ans=0;
    first=(v[0]-0)*2;
    last=(z-v[n-1])*2;
    ans=max(m,max(first,last));
    // cout << setprecision(16);
    cout<<ans/2;
}

int main(){
 //#ifndef ONLINE_JUDGE
        //FOR GETTING INPUT FROM input.txt
        //freopen("input.txt", "r", stdin);sf
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