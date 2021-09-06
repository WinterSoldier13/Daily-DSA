#include<iostream>
#include<bits/stdc++.h>

using namespace std;


vector<pair<int,int> >twoSumIterative(vector<int> arr, int val, int index)
{
    int left = 0;
    int right = arr.size()-1;
    sort(arr.begin(), arr.end());


    vector<pair<int, int>> temp;


    while(left<right)
    {
        int val1 = arr[left];
        int val2 = arr[right];
        if(left == index)
        left++;
        if(right==index)
        right--;

        if(val == val1+val2)
        {
             
             temp.push_back(make_pair(val1, val2));
        }
        if(val > val1+val2)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    // sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(),temp.end()), temp.end());
    return temp;
}


vector<vector<int>> mothership;

void threeSum(vector<int> arr, int val)
{
    
    for(int i =0;i<arr.size();i++)
    {
        int current = arr[i];
        int req = val - current;
        vector<int> xender = arr;
        xender[i] = INT16_MAX-1;
        vector<pair<int, int>> temp = twoSumIterative(xender, req, i);
        for(auto x: temp)
        {
            vector<int> t{current, x.first, x.second};
            sort(t.begin(), t.end());
            mothership.push_back(t);
        }
    }
}

int main()
{
    vector<int> arr{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};

    vector<int> arr2{3,0,-2,-1,1,2};
    sort(arr.begin(), arr.end());

    
    int val =0;
    threeSum(arr2, val);

    sort(mothership.begin(),mothership.end());
    mothership.erase(unique(mothership.begin(), mothership.end()), mothership.end());    


    for(auto x: mothership)
    {
        for(auto c: x)
        cout<<c<<" ";
        cout<<endl;
    }

    // vector<pair<int, int> >temp = twoSumIterative(arr, 5);
    // for(auto pr: temp)
    // {
    //     cout<<pr.first<<" "<<pr.second;
    //     cout<<endl;
    // }
}