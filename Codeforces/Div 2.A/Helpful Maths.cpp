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
  int a1=0,a2=0,a3=0;
  int len=s.size();
  for(int i=0;i<len;i++){
  	if(s.at(i)=='1') a1++;
  	if(s.at(i)=='2') a2++;
  	if(s.at(i)=='3') a3++;
  }
 int count=a1+a2+a3;
  	while(a1!=0){
  		cout<<1;	
  		if(count!=1) cout<<'+';
  		a1--;
  		count--;
  	} 
  	  	while(a2!=0){
  		cout<<2;	
  		if(count!=1) cout<<'+';
  		a2--;
  		count--;
  	} 
  	  	while(a3!=0){
  		cout<<3;	
  		if(count!=1) cout<<'+';
  		a3--;
  		count--;
  	} 
  
}