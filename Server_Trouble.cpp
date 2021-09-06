#include<iostream>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        if(n%k==0)cout<<n/k<<" "<<k;
        else cout<<n/k +1<<" "<<n%k;
        cout<<"\n";
    }
    return 0;
}


//while(condition)
// 8 3