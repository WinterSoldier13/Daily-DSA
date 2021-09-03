#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int4

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &arr)
    {
        reverse(arr.begin(), arr.end());
        stack<int> stack;
        vector<int> out;

        for (int i = 0; i < arr.size(); i++)
        {
            while (!stack.empty() and (arr[stack.top()] <= arr[i]))
            {
                stack.pop();
            }
            if(stack.empty())
            {
                out.push_back(0);
            }
            else
            {
                out.push_back(i-stack.top());
            }
            stack.push(i);   
        }
        reverse(out.begin(), out.end());
        return out;
    }
};