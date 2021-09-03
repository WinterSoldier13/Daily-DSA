#include<bits/stdc++.h>
using namespace std;



void solve(){
    string s;
    getline(cin,s);
    int len=s.size();
    set<char> a;
    char b;
    for(int i=1;i<len-1;i++){
        if(s.at(i)==' ' || s.at(i)==','){
            continue;
        }
        b=s.at(i);
        a.insert(b);
    }
    cout<<a.size();
}

int main(){
  //#ifndef ONLINE_JUDGE
        //FOR GETTING INPUT FROM input.txt
        //freopen("input.txt", "r", stdin);
        //FOR GETTING INPUT FROM input.txt	
        //freopen("output.txt", "w", stdout);
    //#endif
  int t=1;
  //cin>>t;
  while(t--){
     solve();
  }
}