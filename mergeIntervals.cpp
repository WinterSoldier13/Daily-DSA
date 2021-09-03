#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    stack<pair<int,int>> stack;
    int l = intervals.size();
    
    stack.push(make_pair(intervals[0][0], intervals[0][1]));
    
    for(int i=1;i<l;i++)
    {
        vector<int> c = intervals[i];

        int x = c[0];
        int y = c[1];

        int currentX = stack.top().first;
        int currentY = stack.top().second;
        
        
        if(currentX<=x and x<=currentY)
        {
            stack.pop();
            stack.push(make_pair(currentX, max(currentY,y)));
        }
        else if(x>currentY)
        {
            stack.push(make_pair(x,y));
        }
    }
    vector<vector<int>> out;
    
    while(!stack.empty())
    {
        vector<int> temp{stack.top().first, stack.top().second};
        out.push_back(temp);
        stack.pop();
    }
    reverse(out.begin(), out.end());
    return out;
    
}

int main()
{
    vector<vector<int>> arr{{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> arr2{{1,4},{0,4}};

    for (auto x: merge(arr2))
    {
        cout<<x[0]<<" "<<x[1]<<endl;
    }
}