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
  int temp[n];
  copy(arr,arr+n,temp);
  int min=0;
  int max=0;
  sort(temp,temp+n);
  min=temp[0];
  max=temp[n-1];
  int ans=0;
  int maxi,mini;
  for (int i = 0; i < n; i++)
  {
  	if(arr[i]==max) {
  		maxi=i;
  		break;
  	}
  	ans++;

  }
  //cout<<ans<<"\n";
  for (int i = n-1; i >= 0; i--)
  {
  	if(arr[i]==min){
  		mini=i;
  	 break;	
  	}
  	ans++;
  }
  //cout<<ans<<"\n";
  //int maxi,mini;
  
  //cout<<maxi<<"\t"<<mini<<"\n";
  if(maxi>mini) ans--;
  cout<<ans;
}