#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    void printMat(vector<vector<int>> &arr)
    {
        for(auto x: arr)
        {
            for(auto c: x)
            {
                cout<<c<<" ";
            }
            cout<<endl;
        }
    }
    int trapRainWater(vector<vector<int>> &arr)
    {
        int rows = arr.size();
        int cols = arr[0].size();
        if (rows == 0 or rows == 1 or cols == 0 or cols == 1)
        {
            return 0;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        vector<int> t(cols, -1);
        vector<vector<int>> dp(rows, t);

        int currentMax = INT32_MIN;

        // First push all the boundary in the minHeap according to their height
        // pushing 1st row
        for (int i = 0; i < cols; i++)
        {
            minHeap.push({arr[0][i], {0, i}});
            dp[0][i] = 0;
        }
        // pushing the last row
        for (int i = 0; i < cols; i++)
        {
            minHeap.push({arr[rows - 1][i], {rows - 1, i}});
            dp[rows-1][i] = 0;
        }
        // pushing the first col
        for (int i = 1; i < rows - 1; i++)
        {
            minHeap.push({arr[i][0], {i, 0}});
            dp[i][0] = 0;
        }
        // pushing the last col
        for (int i = 1; i < rows - 1; i++)
        {
            minHeap.push({arr[i][cols - 1], {i, cols - 1}});
            dp[i][cols-1] = 0;
        }
        vector<int> xDir{-1, 0, 1, 0};
        vector<int> yDir{0, 1, 0, -1};


        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();

            int currHeight = top.first;
            int currX = top.second.first;
            int currY = top.second.second;
            // cout<<currHeight<<" "<<"{"<<currX<<","<<currY<<"}"<<endl;
            // check if its less than max and update
            currentMax = max(currentMax, currHeight);
            

            // traverse it's neighbours

            for (int i = 0; i < 4; i++)
            {
                int newX = currX + xDir[i];
                int newY = currY + yDir[i];

                if (newX >= 0 and newX < rows and newY >= 0 and newY < cols and dp[newX][newY] == -1)
                {
                    int valAtNew = arr[newX][newY];
                    if (valAtNew < currentMax)
                    {
                        dp[newX][newY] = currentMax - valAtNew;
                    }
                    else
                    {
                        dp[newX][newY] = 0;
                    }
                    
                    minHeap.push({valAtNew, {newX, newY}});
                }
            
            }
        }
        // printMat(dp);
        int totalSum = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                totalSum += dp[i][j];
            }
        }
        return totalSum;
    }
};
int main()
{
    vector<vector<int>> arr{{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};


    Solution ob;
    ob.printMat(arr);
    cout<<ob.trapRainWater(arr)<<endl;
}