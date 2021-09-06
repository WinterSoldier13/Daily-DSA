#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    vector<int> out;
    for(int z=0;z<t;z++)
    {
        int n, k;
        cin>>n>>k;

        vector<int> arr(n,0);

        for(int i=0;i<n;i++)
        cin>>arr[i];

        sort(arr.begin(), arr.end());

        int prevMinimums = 0;
        int count = INT32_MAX;

        for(int i=0;i<n;i++)
        {
            int removed = prevMinimums; // If i REmovee all the previous minimums
            prevMinimums+=arr[i];

            //Now normalize the pile starting from the largest ele considering current as smallest
            // as we have already removed all the prev smaller piles
            for(int j = arr.size()-1;j>i;j--)
            {
                removed+= (arr[j]-arr[i]>k)?(arr[j]-arr[i]-k):0;
            }

            count = min(count, removed);
        }
        out.push_back(count);
    }
    for(auto x: out)
    cout<<x<<endl;
}
// For the first iteration we do NOT remove any pile instead we just normalize other piles and store the ans.
// By normalizing I mean currentPileHeight - minPile present
// from the second iteration onwards we consider oue previous min pile completely removed... which makes sense 
// because we should remove only the min pile and then we add the normalized value from the back