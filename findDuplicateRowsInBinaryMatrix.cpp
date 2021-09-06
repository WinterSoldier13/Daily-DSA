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
// #define lli long long int
private:
    lli convertRow2num(vector<int> &arr, int maxPower2)
    {
        lli sum = 0;

        for (auto x : arr)
        {
            sum += (x* pow(2, maxPower2--));
        }
        return sum;
    }

public:
    vector<int> repeatedRows(vector<vector<int>> arr, int rows, int cols)
    {
        int maxPowerof2 = cols - 1;
        unordered_set<lli> hashset;
        vector<int> out;
        for (int i = 0; i < rows; i++)
        {
            lli num = convertRow2num(arr[i], maxPowerof2);
            if (hashset.count(num))
            {
                out.push_back(i+1);
            }
            hashset.insert(num);
        }

        return out;
    }
};

int main()
{
    vector<vector<int>> arr{{1, 1, 0, 1, 0, 1},
                            {0, 0, 1, 0, 0, 1},
                            {1, 0, 1, 1, 0, 0},
                            {1, 1, 0, 1, 0, 1},
                            {0, 0, 1, 0, 0, 1},
                            {0, 0, 1, 0, 0, 1}};
    int rows = arr.size();
    int cols = arr[0].size();

    Solution ob;

    auto ans = ob.repeatedRows(arr, rows, cols);

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}