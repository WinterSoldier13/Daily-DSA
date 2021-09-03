#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>


int main()
{
 	fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);
    
    lli t;
    cin>>t;
    
    while(t--)
    {
        lli n,m;
        cin>>n>>m;
        
        unordered_set<lli> hashset;
        vector<lli> arr;
        for(lli i=0;i<n;i++)
        {
            lli temp;
            cin>>temp;
            hashset.insert(temp);
            arr.push_back(temp);
        }
        
        for(lli i=0;i<m;i++)
        {
            lli temp;
            cin>>temp;
            
            if(hashset.count(temp))
            {
                hashset.erase(temp);
            }
        }
        
for(auto x: arr)
{
    if(hashset.count(x))
    cout<<x<<" ";
}
        cout<<endl;
    }
	//code
	return 0;
}