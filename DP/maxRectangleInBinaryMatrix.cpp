#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maxAreaHistogram(vector<int> arr)
{
    stack<int> stack;
    int max_area = 0;
    int area;
    int i = 0;

    while(i<arr.size())
    {
        int current_element = arr[i];
        
        if(stack.empty() or arr[stack.top()]<=current_element)
        {
            stack.push(i);
            i++;
        }

        else
        {
            int tp = stack.top();
            stack.pop();
            if(stack.empty())
            {
                area = arr[tp]*i;
            }
            else
            {
                area = arr[tp]*(i-stack.top()-1);
            }

            max_area = max(max_area,area);
            
        }
        
    }
    while(!stack.empty())
    {
        int tp= stack.top();
        stack.pop();
        if(stack.empty()) area = arr[tp]*i;
        else area= arr[tp]*(i-stack.top()-1);
        max_area = max(max_area,area);

    }

    return max_area;

}





int maxRectangle(vector<vector<int>> arr)
{
    int max_area= maxAreaHistogram(arr[0]);
    vector<int> temp = arr[0];

    for(int i=1;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            if(arr[i][j] == 0)
            {
                temp[j] =0;
            }
            else
            {
                temp[j]+=arr[i][j];
            }
        }
        int area = maxAreaHistogram(temp);
        max_area = max(max_area,area);
    }
    return max_area;
}

int main()
{
    vector<vector<int>> arr{{1,0,1,0,0},
                            {1,0,1,1,1},
                            {1,1,1,1,1},
                            {1,0,0,1,0}};

    cout<<maxAreaHistogram(arr[1])<<endl;

    cout<<maxRectangle(arr)<<endl;
}