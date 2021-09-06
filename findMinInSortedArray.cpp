#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

class Solution
{
public:

    
    int findMin(vector<int> &arr)
    {
        if(arr.size() == 1)
        {
            return arr[0];
        }

        if(is_sorted(arr.begin(), arr.end()))
        {
            return arr[0];
        }
        auto temp = arr;
        reverse(temp.begin(), temp.end());
        if(is_sorted(temp.begin(), temp.end()))
        {
            return temp[0];
        }
        int start = 0;
        int end = arr.size();
        int ans = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[mid + 1] and arr[mid] > arr[mid - 1])
            {
                ans = mid;
                break;
            }
            else if (arr[mid]> arr[0])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        cout<<"ans "<<ans<<endl;
        return arr[ans+1];
    }
};

int main()
{
    vector<int> arr{3,1,2};

    Solution* ob;
    cout<<ob->findMin(arr)<<endl;
}
