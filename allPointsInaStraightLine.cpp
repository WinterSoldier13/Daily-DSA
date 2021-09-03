#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

// WIll NOT work for fuck'n repeated points case
class Solution
{
public:
    pair<double, double> getSlopeIntercept(vector<int> &point1, vector<int> &point2)
    {
        double x1 = point1[0];
        double y1 = point1[1];

        double x2 = point2[0];
        double y2 = point2[1];
        double slope;
        if ((x1 - x2) == 0)
        {
            slope = 1.57;
        }
        else
        {
            slope = (y1 - y2) / (x1 - x2);
        }

        double intercept = y1 - slope * x1;
        return make_pair(slope, intercept);
    }

    int getRoot(int N)
    {
        N = 2*N;

        for(int i=1;i<N/2;i++)
        {
            if( i*(i+1) == N)
            {
                return i+1;
            }
        }
        return -1;
    }
    int maxPoints(vector<vector<int>> &points)
    {
        int l = points.size();
        unordered_map<double, unordered_map<double, int>> hashmap;

        for (int i = 0; i < l; i++)
        {
            for (int j = i + 1; j < l; j++)
            {
                auto point1 = points[i];
                auto point2 = points[j];

                auto p = getSlopeIntercept(point1, point2);

                double slope = p.first;
                double intercept = p.second;

                hashmap[slope][intercept]++;
            }
        }
        int maxL = 0;

        for (auto it = hashmap.begin(); it != hashmap.end(); it++)
        {
            // cout<<"Slope "<<it->first<<" || ";
            for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            {
                // cout<<it2->first<<" "<<it2->second<<" | ";
                maxL = max(maxL, it2->second);
            }
            cout<<endl;
        }
        return getRoot(maxL);
    }
};

int main()
{
    // vector<vector<int>> arr{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    vector<vector<int>> arr{{1,1}, {2,2}, {3,3}};

    Solution *ob;
    cout << ob->maxPoints(arr) << endl;
}