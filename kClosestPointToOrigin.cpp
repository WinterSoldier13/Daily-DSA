#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    double getDis(vector<int> point)
    {
        double x = point[0];
        double y = point[1];

        return sqrt(x * x + y * y);
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        vector<vector<int>> out;
        priority_queue< pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>> > minHeap;

        for(auto point : points)
        {
            double dis = getDis(point);
            minHeap.push(make_pair(dis, point));
        }
        
        while(!minHeap.empty())
        {
            if(K==0)
            {
                break;
            }
            auto top = minHeap.top();
            minHeap.pop();

            out.push_back(top.second);
            K--;
        }
        return out;
    }
};