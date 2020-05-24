#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maxAreaHistogram(vector<int> arr)
{
    stack<int> stack;
    int i=0;
    int max_area, top;
    while(i<arr.size())
    {
        if(stack.empty() or stack.top()<=arr[i])
        {
            stack.push(i++);
        }

        else
        {
            while(!stack.empty())
            {
                top = stack.top();
                stack.pop();
                int area;
                
                if(stack.empty())
                area = arr[top]*i;

                else
                {
                    area = arr[top] *(i-stack.top()-1);
                }
                max_area = max(max_area, area);
            }
        }
        
    }

    while(!stack.empty())
    {
        top = stack.top();
        stack.pop();
        int area;
        
        if(stack.empty())
        area = arr[top]*i;

        else
        {
            area = arr[top] *(i-stack.top()-1);
        }
        max_area = max(max_area, area);
    }
    return max_area;

}