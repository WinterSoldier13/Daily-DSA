#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void solve(){
    int n,m;
    cin>>n>>m;
    string a[m],b[m];
    string c[n];
    for(int i=0;i<m;i++){
        cin>>a[i];
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    // for(auto x:a)cout<<x<<" ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(c[i]==a[j]){
                int alen=0,blen=0;
                alen=a[j].size();
                blen=b[j].size();
                if(blen<alen)cout<<b[j];
                else cout<<a[j];
                cout<<" ";
            }
        }
    }

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