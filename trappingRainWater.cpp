#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int trap(vector<int>& height) 
    {
        vector<int> leftMax = {height[0]};
        int maxSoFar = height[0];

        vector<int> rightMax;
        int l = height.size();
        
        for(int i =1;i<l;i++)
        {
            maxSoFar = max(maxSoFar, height[i]);

            leftMax.push_back(maxSoFar);
        }
        
        
        reverse(height.begin(), height.end());
        
        maxSoFar = height[0];
        rightMax.push_back(height[0]);

        for(int i =1;i<l;i++)
        {
            maxSoFar = max(maxSoFar, height[i]);

            rightMax.push_back(maxSoFar);
        }
        reverse(rightMax.begin(), rightMax.end());
        reverse(height.begin(), height.end());

        


        int sum=0;

        for(int i=0;i<l;i++)
        {
            cout<<leftMax[i]<<"  "<<rightMax[i]<<" ";
            sum+=(min(leftMax[i], rightMax[i])-height[i]);
            cout<<sum<<endl;

        }
        cout<< sum<<endl;


        
        return 0;
        
    }

    int main()
    {
        vector<int> arr{0,1,0,2,1,0,1,3,2,1,2,1};
        trap(arr);
    }