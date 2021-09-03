#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
  	cin>>arr[i];
  }
  sort(arr,arr+n);
  int tot=0;
  for(auto i:arr) tot+=i;
  	int count=0;
    int sum=0;
    while(sum<=tot/2){
    	sum+=arr[n-1];
    	n--;
    	count++;
    }
    cout<<count;
}