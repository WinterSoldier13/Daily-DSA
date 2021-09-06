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

    unordered_map<int, int> hashmap;

    void __init__(int n)
    {
        hashmap.clear();
    }

    void getFactors(int n)
    {

        for (int i = 1; i <= (n); i++)
        {
            if (n % i == 0)
            {
                hashmap[i]++;
            }
        }
    }

    void doPreprocessing(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            getFactors(arr[i]);
        }
    }

public:
    void solve(vector<int> &arr, vector<int> &queries)
    {
        int n = arr.size();
        int m = queries.size();

        __init__(n);
        doPreprocessing(arr);

        for (auto x : queries)
        {

            if (hashmap.find(x) == hashmap.end())
                cout << 0 << " ";
            else
            {
                cout << hashmap[x] << " ";
            }
        }
        cout << endl;
    }
    ~Solution()
    {
        hashmap.clear();
    }
};

int main()
{
    fast_cin();

    getT()
    {
        int n, m;
        cin >> n >> m;

        vector<int> arr(n, 0);
        vector<int> queries(m, 0);

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < m; i++)
            cin >> queries[i];

        Solution ob;
        ob.solve(arr, queries);
    }
    return 0;
}