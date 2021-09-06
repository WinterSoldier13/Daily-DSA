#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

int recurse(vector<int> &arr1, vector<int> &arr2, int index, int r1, int r2)
{
    if(index == 0 or (r1<=0 and r2<=0))
    {
        return 0;
    }
    int ans;
    int ans1 = INT_MIN;
    int ans2 = INT_MIN;
    if(r1 > 0)
    {
        ans1 = arr1[index-1] + recurse(arr1, arr2, index-1, r1-1, r2);
    }
    if(r2>0)
    {
        ans2 = arr2[index-1] + recurse(arr1, arr2, index-1, r1, r2-1);
    }

    return max(ans1, ans2);
}

void solve(vector<int> arr1, vector<int> arr2, int n, int x, int y)
{
    cout<<recurse(arr1, arr2, n, x, y)<<endl;

}

int main()
{
 	fast_cin();
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n, x, y;
        cin>>n>>x>>y;

        vector<int> arr1(n);
        vector<int> arr2(n);

        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>arr2[i];
        }

        solve(arr1, arr2, n, x, y);
    }
	return 0;
}