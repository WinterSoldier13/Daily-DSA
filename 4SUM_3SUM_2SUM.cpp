#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> twoSum(vector<int> nums, int target, int forbiddenIndex1, int forbiddenIndex2)
{
    unordered_map<int, int> hashmap;
    vector<vector<int>> out;

    for(int i=0;i<nums.size(); i++)
    {
        if(i==forbiddenIndex1 or i==forbiddenIndex2)
        {
            continue;
        }
        int e3 = nums[i];
        int req = target - e3;

        if(hashmap.find(req) != hashmap.end())
        {
            vector<int> temp{e3, req};
            sort(temp.begin(), temp.end());
            out.push_back(temp);
        }
        else
        {
            hashmap[e3] = req;
        }
    }
    out.erase(unique(out.begin(), out.end()), out.end());
    sort(out.begin(), out.end());
    return out;
}


vector<vector<int>> threeSum(vector<int> nums, int target, int forbiddenIndex1)
{
    vector<vector<int>> out;

    int l = nums.size();

    for(int i=0;i<l;i++)
    {
        if(i== forbiddenIndex1)
        {
            continue;
        }
        int e2 = nums[i];
        int reqE2 = target - e2;

        vector<vector<int>> temp = twoSum(nums, reqE2, forbiddenIndex1, i);
        if(temp.size()!=0)
        {
            for(auto x: temp)
            {
                x.push_back(e2);
                sort(x.begin(), x.end());
                out.push_back(x);
            }
        }
    }
    out.erase(unique(out.begin(), out.end()), out.end());
    sort(out.begin(), out.end());

    return out;
}





vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    sort(nums.begin(), nums.end());

    int l = nums.size();

    vector<vector<int>> out;

    for(int i=0;i<l;i++)
    {
        int e1 = nums[i];
        int remE1 = target - e1;

        vector<vector<int>> temp = threeSum(nums, remE1, i);

        if(temp.size()!=0)
        {
            for(auto x: temp)
            {
                x.push_back(e1);
                sort(x.begin(), x.end());
                out.push_back(x);
            }
        }
    }
    out.erase(unique(out.begin(), out.end()), out.end());
    sort(out.begin(), out.end());
    out.erase(unique(out.begin(), out.end()), out.end());
    sort(out.begin(), out.end());
    return out;
}

int main()
{
    vector<int> temp{10,2,3,4,5,7,8};
    int target = 23;

    for(auto x: fourSum(temp, target))
    {
        for(auto c:x)
        cout<<c<<" ";
        cout<<endl;
    }
}