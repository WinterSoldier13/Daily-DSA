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
#define pii pair<double, int>

class Solution
{
private:
    vector<int> cummulativeFreq;

public:
    void __init__(vector<int> &arr)
    {
        int sum = 0;
        for (auto x : arr)
        {
            sum += x;
            cummulativeFreq.push_back(sum);
        }
    }

    void solve(int l, int r)
    {
        if(l-2 < 0)
        {
            cout<<cummulativeFreq[r-1]<<" ";
            return;
        }
        cout<< cummulativeFreq[r-1]-cummulativeFreq[l-2] << " ";
    }
};

int main()
{
    fast_cin();

    getT()
    {
        int n;
        cin >> n;

        Solution ob;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ob.__init__(arr);
        int q;
        cin >> q;

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            ob.solve(l,r);
        }
        cout << endl;
    }
}