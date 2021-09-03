#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void reverse(vector<int> &v){
  if(v.size()<=1)return;
  int first;
  first=v[0];
  // last=v[v.size()-1];
  v.erase(v.begin());
  reverse(v);
  v.push_back(first);

}


int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt  
    freopen("output2.txt", "w", stdout);
  #endif
  int t;
  cin>>t;
  while(t){
   int n;
   cin>>n;
   vector<int> v(n);
   for(auto &x:v)cin>>x;
   reverse(v);
   for(auto x:v)cout<<x<<"\t";
  t--;
  }
}