#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
    int t;
    cin>>t;
    while(t--){
    string str;
    cin>>str;
    if(str.length()>10)
    cout<<str.at(0)<<str.length()-2<<str.at(str.length()-1);
    else cout<<str;
    cout<<endl;
    }
}
