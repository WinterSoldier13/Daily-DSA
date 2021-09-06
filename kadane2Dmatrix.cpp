#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define tiiii tuple<int, int, int, int>

int kadane(vector<int> &arr, int *start, int *finish, int n)
{
    int sum = 0, maxSum = INT_MIN, i;
    *finish = -1;

    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    if (*finish != -1)
        return maxSum;

    maxSum = arr[0];
    *start = *finish = 0;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

// The main function that finds
// maximum sum rectangle in M[][]
void findMaxSum(vector<vector<int>> arr)
{
    int rows = arr.size();
    int cols = arr[0].size();

    // Variables to store the final output
    int maxSum = INT_MIN, finalLeft, finalRight,
        finalTop, finalBottom;

    int left, right, i;

    int sum, start, finish;

    for (left = 0; left < cols; ++left)
    {

        vector<int> temp(rows, 0);

        for (right = left; right < cols; ++right)
        {

            // Calculate sum between current left
            // and right for every row 'i'
            for (i = 0; i < rows; ++i)
                temp[i] += arr[i][right];

            // Find the maximum sum subarray in temp[].
            // The kadane() function also sets values
            // of start and finish. So 'sum' is sum of
            // rectangle between (start, left) and
            // (finish, right) which is the maximum sum
            // with boundary columns strictly as left
            // and right.
            sum = kadane(temp, &start, &finish, rows);

            // Compare sum with maximum sum so far.
            // If sum is more, then update maxSum and
            // other output values
            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    // Print final values
    // cout << "(Top, Left) (" << finalTop
    //      << ", " << finalLeft << ")" << endl;
    // cout << "(Bottom, Right) (" << finalBottom
    //      << ", " << finalRight << ")" << endl;
    cout << maxSum << endl;
}

int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int rows, cols;
        cin >> rows >> cols;
        vector<int> temp(cols, 0);
        vector<vector<int>> arr(rows, temp);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> arr[i][j];
            }
        }
        findMaxSum(arr);
    }
}