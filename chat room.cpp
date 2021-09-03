#include<bits/stdc++.h>
using namespace std;

int main(){
  // #ifndef ONLINE_JUDGE
  //   //FOR GETTING INPUT FROM input.txt
  //   freopen("input.txt", "r", stdin);
  //   //FOR GETTING INPUT FROM input.txt	
  //   freopen("output.txt", "w", stdout);
  // #endif
  string s;
  cin>>s;
  transform(s.begin(),s.end(),s.begin(),::tolower);
  int n=s.size();
  int j=0;
  string a="hello";
  int count=0;
  for(int i=0;i<n;i++){
  	if(count == 4 && s.at(i)=='o'){
  		count++;
  		break;	
  	} 
  	if(a.at(j)==s.at(i)){
  		count++;
  		j++;
  	}
  }
  if(count==5) cout<<"YES";
  else cout<<"NO";
}