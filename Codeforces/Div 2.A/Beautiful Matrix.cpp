#include<bits/stdc++.h>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    //FOR GETTING INPUT FROM input.txt
    freopen("input.txt", "r", stdin);
    //FOR GETTING INPUT FROM input.txt	
    freopen("output.txt", "w", stdout);
  #endif
  int arr[5][5];
  int a,b;
  for(int i=0;i<5;i++){
  	for(int j=0;j<5;j++){
  		cin>>arr[i][j];
  		if(arr[i][j]==1){
  			a=i;b=j;
  		}
  	}
  }
  cout<<abs(2-a)+abs(2-b);
}