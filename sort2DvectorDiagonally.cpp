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

// https://www.geeksforgeeks.org/median-of-two-sorted-arrays/

class Solution
{
public:
    void diagonalSort(vector<vector<int>> &arr, int rows, int cols)
    {
        for (int i = cols - 1; i > 0; i--)
        {
            int row = 0;
            int col = i;
            vector<int> temp;
            while (col < cols and row < rows)
            {
                temp.push_back(arr[row][col]);
                col++;
                row++;
            }
            sort(temp.begin(), temp.end());
            reverse(temp.begin(), temp.end());

            row = 0;
            col = i;
            int index = 0;
            while (col < cols and row < rows)
            {
                arr[row][col] = temp[index++];
                row++;
                col++;
            }
        }

        for (int i = 1; i < rows; i++)
        {
            int row = i;
            int col = 0;
            vector<int> temp;
            while (row < rows and col < cols)
            {
                temp.push_back(arr[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(), temp.end());
 
            int index = 0;

            row = i;
            col = 0;

            while (row < rows and col < cols)
            {
                arr[row][col] = temp[index++];
                row++;
                col++;
            }
        }

        for (auto x : arr)
        {
            for (auto c : x)
            {
                cout << c << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    fast_cin();

    vector<vector<int>> arr{
        {9, 3, 2, 1},
        {1, 5, 2, 1},
        {2, 2, 4, 1},
        {3, 3, 3, 7}};

    int n = arr.size();
    int m = arr[0].size();

    Solution ob;
    ob.diagonalSort(arr, n, m);
    return 0;
}