#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli unsigned long long int

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &arr, int target)
    {
        if (arr.size() == 0 or arr[0].size() == 0)
        {
            return 0;
        }
        int row = 0;
        int col = arr[0].size() - 1;

        while(row<arr.size() and col>=0)
        {
            if(arr[row][col] == target)
            {
                return 1;
            }
            else if(arr[row][col]>target)
            {
                col--;
            }
            else
            {
                row++;
            }
        }
        return 0;
    }
};

int main()
{
    vector<vector<int>> arr{{1, 4, 7, 11, 15},
                            {2, 5, 8, 12, 19},
                            {3, 6, 9, 16, 22},
                            {10, 13, 14, 17, 24},
                            {18, 21, 23, 26, 30}};

    Solution ob;
    cout << ob.searchMatrix(arr, 20) << endl;
}