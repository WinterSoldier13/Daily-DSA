#include<iostream>
#include<algorithm>
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
  while(t){
   int x1,y1,x2,y2;
   cin>>x1>>y1>>x2>>y2;
   if(x2-x1==0)cout<<x1+y2-y1<<" "<<y1<<" "<<x2+y2-y1<<" "<<y2;
   else if(y2-y1==0)cout<<x1<<" "<<y1+x2-x1<<" "<<x2<<" "<<y2+x2-x1;
   else if(abs(x2-x1)==abs(y2-y1)){
    if(x1>x2){
      swap(x1,x2);
      swap(y1,y2);
    }
    cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;


   }

    else cout<<-1;
  t--;
  }
}