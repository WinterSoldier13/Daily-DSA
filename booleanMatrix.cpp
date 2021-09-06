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

#define pii pair<double, int>

class Solution
{
private:
    void replaceRowsCols(vector<vector<int>> &arr, int alpha, int beta)
    {
        int rows = arr.size();
        int cols = arr[0].size();

        for (int i = 0; i < cols; i++)
        {
            if (arr[alpha][i] != 1)
            {
                arr[alpha][i] = -1;
            }
        }

        for (int i = 0; i < rows; i++)
        {
            if (arr[i][beta] != 1)
            {
                arr[i][beta] = -1;
            }
        }
    }

    void replaceMinusWithPlus(vector<vector<int>> &arr)
    {
        int rows = arr.size();
        int cols = arr[0].size();


        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(arr[i][j] == -1)
                {
                    arr[i][j] = 1;
                }
            }
        }
    }

    void extraSpaceHelper(vector<vector<int>> &arr)
    {
        int rows = arr.size();
        int cols = arr[0].size();

        vector<int> rowMat(rows, 0);
        vector<int> colMat(cols, 0);

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(arr[i][j] == 1)
                {
                    rowMat[i] = 1;
                    colMat[j] = 1;
                }
            }
        }

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(rowMat[i] or colMat[j])
                {
                    arr[i][j] = 1;
                }
            }
        }
    }

public:
    void booleanMatrix(vector<vector<int>> &arr)
    {
        int rows = arr.size();
        int cols = arr[0].size();

        // for (int i = 0; i < rows; i++)
        // {
        //     for (int j = 0; j < cols; j++)
        //     {
        //         if (arr[i][j] == 1)
        //         {
        //             replaceRowsCols(arr, i, j);
        //         }
        //     }
        // }

        // replaceMinusWithPlus(arr);

    }
};

int main()
{
    int arr[] = {4, 8, 12, 16};
    int n = 4;

    Solution ob;
    cout << ob.maxAND(arr, n) << endl;
    return 0;
}