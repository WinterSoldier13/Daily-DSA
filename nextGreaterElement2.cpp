#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tup tuple<int, int>

vector<int> nextGreaterElements(vector<int> &nums)
{
    int l = nums.size();
    vector<int> out(l);
    if(nums.size() == 0)
    {
        return nums;
    }
    stack<int> stack;

    reverse(nums.begin(), nums.end());

    for(int i=0;i<l;i++)
    {
        if(stack.empty())
        {
            stack.push(nums[0]);
            out[i] = -1;
            continue;
        }
        while (!stack.empty() and stack.top()<=nums[i])
        {
            stack.pop();
        }
        if(stack.empty())
        {
            out[i] = -1;
        }
        else
        {
            out[i] = stack.top();
        }
        stack.push(nums[i]);
    }
    for(int i=0;i<l;i++)
    {
        if(stack.empty())
        {
            stack.push(nums[0]);
            out[i] = -1;
            continue;
        }
        while (!stack.empty() and stack.top()<=nums[i])
        {
            stack.pop();
        }
        if(stack.empty())
        {
            out[i] = -1;
        }
        else
        {
            out[i] = stack.top();
        }
        stack.push(nums[i]);
    }
    reverse(out.begin(), out.end());
    return out;
}