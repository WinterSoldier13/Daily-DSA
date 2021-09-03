#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int maxAreaOfHistogram(vector<int> arr)
{
    int n = arr.size();
    int maxArea = 0;
    int top = 0;
    stack<int> stack;
    int ptr = 0;

    while (ptr < n)
    {
        if (stack.empty() or arr[ptr] >= arr[stack.top()])
        {
            stack.push(ptr);
            ptr++;
        }
        else
        {

            int height = arr[stack.top()];
            stack.pop();

            int width;
            if (stack.size() == 0)
            {
                width = ptr;
            }
            else
            {
                width = ptr - stack.top() - 1;
            }
            int area = height * width;

            maxArea = max(maxArea, area);
        }
    }
    while (!stack.empty())
    {
        int height = arr[stack.top()];
        stack.pop();

        int width;
        if (stack.size() == 0)
        {
            width = ptr;
        }
        else
        {
            width = ptr - stack.top() - 1;
        }
        int area = height * width;

        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();

    if (rows == 0 or cols == 0)
    {
        return 0;
    }

    int maxArea = 0;

    vector<int> holding;

    for (auto x : arr[0])
    {
        holding.push_back(x - '0');
    }

    maxArea = maxAreaOfHistogram(holding);
    for (int i = 1; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] - '0' == 1)
            {
                holding[j] += 1;
            }
            else
            {
                holding[j] = 0;
            }
        }
        for (auto x : holding)
            cout << x << " ";
        cout << endl;
        maxArea = max(maxArea, maxAreaOfHistogram(holding));
    }
    return maxArea;
}

int main()
{
    vector<vector<char>> arr{{'1', '0', '1', '0', '0'},
                             {'1', '0', '1', '1', '1'},
                             {'1', '1', '1', '1', '1'},
                             {'1', '0', '0', '1', '0'}};

    vector<vector<char>> arr2{{'0', '1'}};

    cout << maximalRectangle(arr2) << endl;
}