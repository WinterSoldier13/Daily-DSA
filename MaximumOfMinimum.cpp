#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{

private:
public:
    // Function to print maximum of minimum of every window size
    // arr[]: input array
    // N: size of array
    vector<int> maxOfMin(int arr[], int n)
    {
        // store closest min to the right
        vector<int> right(n);
        // store closest min to the left
        vector<int> left(n);

        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() and arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                left[i] = -1;
            }
            else
            {
                left[i] = s.top();
            }
            s.push(i);
        }

        while (!s.empty())
        {
            s.pop();
        }

        reverse(arr, arr + n);

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() and arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                right[i] = n;
            }
            else
            {
                right[i] = n - s.top() - 1;
            }
            s.push(i);
        }
        reverse(right.begin(), right.end());
        reverse(arr, arr + n);

        // for(auto x: left)
        //     cout<<x<<" ";
        // cout<<endl;
        
        // for(auto x: right)
        //     cout<<x<<" ";
        // cout<<endl;

        vector<int> ans(n+1, 0);

        for (int i = 0; i < n; i++)
        {
            int len = right[i] - left[i] - 1;

            ans[len] = max(ans[len], arr[i]);
        }

        for (int i = n - 1; i >= 1; i--)
        {
            ans[i] = max(ans[i], ans[i + 1]);
        }
        // cout<<"reach++"<<endl;
        reverse(ans.begin(), ans.end());
        ans.pop_back();
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    fast_cin();

    int arr[] = {10,20,30,50,10,70,30};
    int n = sizeof(arr)/sizeof(arr[0]);

    Solution ob;
    auto ans = ob.maxOfMin(arr, n);
    for(auto x: ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}