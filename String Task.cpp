#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  string str;
  cin>>str;
  transform(str.begin(),str.end(),str.begin(),::tolower);
  //cout<<str;
  string arr="aeiouy";
  int length=str.length();
  for(int i=0;i<length;i++){
  	if(arr.find(str.at(i))>5)
  		cout<<'.'<<str.at(i);
  }
}