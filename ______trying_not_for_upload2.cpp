#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

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
   int n,k;
   cin>>n>>k;
   int nt=n/2;
   // if(n%2!=0)nt--;
   // int nt=ceil(n/2);
   int arr[n];
   // if(n%2!=0)nt--;
   for(int i=0;i<n;i++) cin>>arr[i];
   sort(arr,arr+n);
   if(arr[(nt)]!=-1){
    if(arr[n-1]>k) cout<<"Too Slow";
    else if(arr[0]!=-1)cout<<"Bot";
    else cout<<"Accepted";
   }
   else cout<<"Rejected";
   cout<<"\n";
  t--;
  }
}