#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

int minFallingPathSum(vector<vector<int>> &arr)
{

    int rows = arr.size();
    int cols = arr[0].size();
    int minSum = 0;
    int prevIndex = -1;

    for (int i = 0; i < rows; i++)
    {
        auto it = min_element(arr[i].begin(), arr[i].end());
        int minEle = *it;
        int minEleIndex = it - arr[i].begin();
        if (minEleIndex == prevIndex)
        {
            arr[i][minEleIndex] = INT16_MAX;
            it = min_element(arr[i].begin(), arr[i].end());
            minEle = *it;
            minEleIndex = it - arr[i].begin();
        }
        cout << minEle << " " << minEleIndex << endl;
        minSum += minEle;
        prevIndex = minEleIndex;
    }
    cout << minSum << endl;
    return minSum;
}
int main()
{
    fast_cin();
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> arr{{-37, 51, -36, 34, -22},
                            {82, 4, 30, 14, 38},
                            {-68, -52, -92, 65, -85},
                            {-49, -3, -77, 8, -19},
                            {-60, -71, -21, -62, -73}};
    minFallingPathSum(arr);
    minFallingPathSum2(arr);
}