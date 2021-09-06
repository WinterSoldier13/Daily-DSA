#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include <utility>
#define int int64_t
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define mp make_pair
#define vin(x,v) for(auto &x:v)cin>>x;
#define vout(x,v)for(auto x:v)cout<<x<<" ";
#define MEM(a, b) memset(a, (b), sizeof(a))
#define loop(i, j, k) for (int i=j ; i<k ; i+=1)
#define rloop(i, j, k) for (int i=j ; i>=k ; i-=1)
#define rep(i, j) loop(i, 0, j)
#define rrep(i, j) rloop(i, j, 0)
#define MP make_pair
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;


bool palindrome(vc arr)
{
    int n=arr.size();
    int flag = 0;
    for (int i = 0; i <= n / 2 && n != 0; i++) {
        if (arr[i] != arr[n - i - 1]) {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        return false;
    else
        return true;
}


void solve(){
    int a,b;cin>>a>>b;
    int aa=a,bb=b;
    string s;cin>>s;
    vc v(s.size());
    int n=s.size();
    if(a%2 && b%2){cout<<-1;return;}
    rep(i,n){
        v[i]=s[i];
    }
    rep(i,n){
        if(v[i]=='?')v[i]=v[n-1-i];
    }
    for(auto x:v){
        if(x=='1')b--;
        if(x=='0')a--;
    }
    if(!palindrome(v)){cout<<-1;return;}

    rep(i,n){
        if(v[i]=='?'){
            if(a>b){
                v[i]='0';
                v[n-1-i]='0';
                a-=2;
            }
            else{
                v[i]='1';
                v[n-1-i]='1';
                b-=2;
            }
        }
    }
    a=b=0;
    for(auto x:v){
        if(x=='0')a++;
        else b++;
    }
    if(palindrome(v)){
        if(a==aa && b==bb)for(auto x:v)cout<<x;
        else cout<<-1;
    }
    else cout<<-1;
    
}

signed main(){
ios_base::sync_with_stdio(false);cin.tie(NULL); 
 //#ifndef ONLINE_JUDGE
        //FOR GETTING INPUT FROM input.txt
        //freopen("input.txt", "r", stdin);
        //FOR GETTING INPUT FROM input.txt	
        //freopen("output.txt", "w", stdout);
//	#endif
  int t=1;
  cin>>t;
  while(t--){
     solve();
  cout<<endl;
  }
}