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
    
    int t;
    cin>>t;
    
    while(t--)
    {
        vector<int> even;
        vector<int> odd;
        
        int n;
        cin>>n;
        for(int i =0;i<n;i++)
        {
            int temp;
            cin>>temp;
            
            if(temp%2 == 0)
            {
                even.push_back(temp);
            }
            else
            {
                odd.push_back(temp);
            }
        }
        for(auto x: even)
        {
            cout<<x<<" ";
        }
        for(auto x: odd)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        
    }
    
    
	//code
	return 0;
}