#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Method 1
class Solution 
{
private:
	vector<int> getLeftMin(vector<int> &arr)
	{
		int l = arr.size();
		stack<int> st;
		vector<int> out(l,0);
		out[0] = -1;
		st.push(arr[0]);
	
		for(int i=1;i<l;i++)
		{
			while(!st.empty() and arr[st.top()]>=arr[i])
			{
				st.pop();		
			}	
			if(st.empty()) out[i] = -1;
			else out[i] = st.top();
			st.push(i);
		}
		return out;
	}
	vector<int> getRightMin(vector<int> &arr)
	{
		int l = arr.size();
		stack<int> st;
		vector<int> out(l,0);
		out[l-1] = l;
		st.push(arr.back());

		for(int i=l-2;i>=0;i--)
		{
			while(!st.empty() and arr[st.top()] >= arr[i])
			{
				st.pop();
			}
			if(st.empty())	out[i] = l;
			else out[i] = st.top();		
			st.push(i);
		}
		return out;
	}
public:
    int largestRectangleArea(vector<int>& arr) 
    {
		int len = arr.size();
		vector<int> leftSmall = getLeftMin(arr);
		vector<int> rightSmall = getRightMin(arr);
		int ans = 0;
		for(int iter=0;iter<len;iter++)
		{
			ans = max(ans, (rightSmall[iter]-leftSmall[iter]-1)*arr[iter]);
		}
		return ans;
    }
};


// Method 2

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