#include <bits/stdc++.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#include <stdio.h>

unordered_map<int, int> hashmap;
int recurse(vector<int> &arr1, vector<int> &arr2, int index)
{
    if(hashmap.find(index) != hashmap.end())
        return hashmap[index];
    if(index >= arr1.size())
    {
        return 0;
    }
    // cout<<index<<endl;
    int ans1 = INT_MAX;
    int ans2 = INT_MAX;

    // take the micro
    ans1 = arr1[index] + recurse(arr1, arr2, index+1);

    // take mono
    for(int i = index+1;i<arr1.size();i++)
    {
        int res;
        if(index == 0)
        {
             res = arr2[i];
        }
        else
            res = arr2[i]-arr2[index-1];
        ans2 = min(ans2, res + recurse(arr1, arr2, i+1));
    }
    return hashmap[index] = min(ans1, ans2);
}



int main()
{
    // vector<int> arr1{3,5,2,1,9};
    // vector<int> arr2{1,1,10,5,3};

    vector<int> arr1{1,2,1,3,4,2,1,2,3,1};
    vector<int> arr2{5,5,1,1,1,5,5,1,1,1};
    


    int n = arr1.size();
    vector<int> preSum{arr2[0]};
    hashmap.clear();

    for(int i=1;i<n;i++)
    {
        preSum.push_back(preSum.back() + arr2[i]);
    }

    // for(auto x: preSum)
    //     cout<<x<<" ";
    // cout<<endl;

    cout<<recurse(arr1, preSum, 0)<<endl;
    return 0;
}
