#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class Solution
{
public:
    vector<int> antiDiagonalPattern(vector<vector<int>> arr)
    {
        int n = arr.size();
        vector<int> out;

        for (int i = 0; i < n; i++)
        {
            int col = i;
            for (int row = 0; row <= i; row++)
            {
                out.push_back(arr[row][col--]);
            }
        }

        // remaining elements
        for (int i = 1; i < n; i++)
        {
            int row = i;
            int col = n - 1;

            while (row < n and col >= 0)
            {
                out.push_back(arr[row++][col--]);
            }
        }

        return out;
    }
};

int main()
{
    vector<vector<int>> arr{{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};

    Solution ob;
    auto ans = ob.antiDiagonalPattern(arr);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}