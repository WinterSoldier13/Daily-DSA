#include<bits/stdc++.h>
// #include<multimap>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output2.txt", "w", stdout);
  #endif
  int t;
  t=1;
  // cin>>t;
  while(t){
   int s,n;
   cin>>s>>n;
   multimap<int, int> m;
   while(n--){
   	int a,b;
   	cin>>a>>b;
   	m.insert({a,b});
   }
   bool ans=true;
   
   	for(auto x:m){
   		if(s>x.first)s+=x.second;
   		else ans=false;

   	}

   if(ans)cout<<"YES";
   else cout<<"NO";
   // for(auto x:m)cout<<x.first<<"\t"<<x.second<<"\n";
  t--;
  }
}