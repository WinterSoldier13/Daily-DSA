#include <iostream>
#include <bits/stdc++.h>

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