#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

class Solution
{
public:
    int pivotElement(vector<int> &arr)
    {
        int l = arr.size();
        int start = 0;
        int end = l;
        int ans = 0;

        //check for decreasing order
        if (arr[0] > arr[1] and arr[l - 2] > arr[l - 1])
        {
            ans = -1;
        }
        else
        {
            if (arr[0] >= arr[l - 1])
            {

                while (start <= end)
                {
                    int mid = start + (end - start) / 2;

                    if (arr[mid] > arr[mid + 1])
                    {
                        ans = mid;
                        break;
                    }
                    if (arr[start] <= arr[mid])
                    {
                        start = mid + 1;
                    }
                    else
                    {
                        end = mid - 1;
                    }
                }
            }
        }

        return ans;
    }
    bool search(vector<int> &arr, int target)
    {
        int piviot = pivotElement(arr);
        cout << piviot << endl;

        if (is_sorted(arr.begin(), arr.end()))
        {
            cout << 1 << endl;
            return binary_search(arr.begin(), arr.end(), target);
        }
        if (piviot < 0)
        {
            cout << 2 << endl;

            reverse(arr.begin(), arr.end());
            return binary_search(arr.begin(), arr.end(), target);
        }

        if (target > arr[piviot])
        {
            cout << 3 << endl;

            return 0;
        }
        if (target<=arr[piviot] and target>=arr[0])
        {
            cout << 4 << endl;

            vector<int> temp;
            auto it = arr.begin();
            for(int i=0;it!=arr.begin()+piviot+1;i++)
            {
                temp.push_back(arr[i]);
                it++;
            }
            for(auto x: temp)
            cout<<x<<" ";
            cout<<endl;
            return binary_search(temp.begin(), temp.end(), target);
        }
        else
        {
            cout << 5 << endl;
            vector<int> temp;
            auto it = arr.begin() + piviot;
            for(int i=piviot+1;it!=arr.end()-1;i++)
            {
                temp.push_back(arr[i]);
                it++;
            }
            for(auto x: temp)
            cout<<x<<" ";
            cout<<endl;
            return binary_search(temp.begin(), temp.end(), target);
        }
        cout << 6 << endl;

        return 0;
    }
};

int main()
{
    fast_cin();
    cin.tie(0);
    cout.tie(0);

    vector<int> arr{6,6,6,6,6,7,0,0,1,2,3,4,5};
    int target = 0;

    Solution ob;

    int p = ob.search(arr, 6);
    cout << p << endl;
}