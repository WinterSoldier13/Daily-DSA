#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int binary(vector<int> &arr)
    {
        int l = arr.size();
        int start = 0;
        int end = l-1;
        int ans = -1;
        
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            if(mid<l-1 and arr[mid]>arr[mid+1])
            {
                ans = mid;
                break;
            }
            else if(arr[mid]<arr[0])
            {
                end = mid-1;
                ans = end;
            }
            else
            {
                start = mid+1;
            }
        }
        return ans;
    }
    int solve(vector<int>& arr) 
    {
        if(arr.size() == 1)
        {
            return arr[0];
        }
        if(is_sorted(arr.begin(), arr.end()))
        {
            return arr[arr.size()-1];
        }
        return arr[binary(arr)]; 
    }
};