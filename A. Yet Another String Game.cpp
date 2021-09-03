#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void first(char a){
    if(a=='a')cout<<'b';
  	else cout<<'a';
}


void last(char a){
	if(a=='z')cout<<'y';
  	else cout<<'z';
}


void solve(){
  int len;
  string s;
  cin>>s;
  len=s.length();
  vector<char> v(len);
  int i=0;
  while(i<len){
  	if(i%2==0)first(s.at(i));
  	else last(s.at(i));
  	i++;
  }
  // cout<<v[0];
  // for(auto x:v)cout<<x;
}

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  int t=1;
  cin>>t;
  while(t--){
   solve();
   cout<<"\n";
  }
}