#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  string s;
  cin>>s;
  int n;
  n=s.size();
  string a="";
  for(int i=0;i<n;i++){
  	if(s.at(i)=='W' && s.at(i+1)=='U' && s.at(i+2)=='B'){
  		i=i+2;
  		a.append(" ");
  	}
  	else{
  		a+=s.at(i);
  	}
  }
  //cout<<a;
  //a+=" ";
  n=a.size();
  for(int i=0;i<n-1;i++){
  	if(a.at(i)==' ' && a.at(i+1)==' '){
  		a.erase(i,1);
  		n--;
  	}
  }
  while(a.at(0)==' '){
  	a.erase(0,1);
  }
  n=a.size();
  while(a.at(n-1)==' '){
  	a.erase(n--,1);
  }
  cout<<a;
}