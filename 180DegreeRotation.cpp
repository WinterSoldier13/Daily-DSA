#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int


int main()
 {
	fast_cin();
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    vector<vector<int>> arr(n , vector<int>(n));
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>arr[i][j];
	        }
	        reverse(arr[i].begin(), arr[i].end());
	    }
	    reverse(arr.begin(), arr.end());
	    for(auto x: arr)
	    {
	        for(auto c: x)
	        {
	            cout<<c<<" ";
	        }
	        cout<<endl;
	    }
	}
	
	return 0;
}