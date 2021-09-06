#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

int minimumTotal(vector<vector<int>> &triangle)
{
    vector<vector<int>> dp;
    for(auto x: triangle)
    {
        vector<int> t(x.size(), INT16_MAX);
        dp.push_back(t);
    }



    for(int i=0;i<triangle[0].size();i++)
    {
        dp[0][i] = triangle[0][i];
    }

    for(int i=1;i<triangle.size();i++)
    {

        for(int j=0;j<triangle[i].size(); j++)
        {
            int currentLength = triangle[i].size();
            int prevLength = triangle[i-1].size();

            int value = dp[i][j];

            if(j-1>=0)
            {
                value = min(value, triangle[i][j] + dp[i-1][j-1]);
            }
            if(j<=prevLength-1)
            {
                value = min(value, triangle[i][j] + dp[i-1][j]);
            }
            if(j+1<prevLength)
            {
                value = min(value, triangle[i][j] + dp[i-1][j+1]);
            }
            dp[i][j] = value;
            // cout<<value<<" ";
        }
        // cout<<endl;

    }
    for (auto x : dp)
    {
        for (auto c : x)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    // return 0;
    return *min_element(dp[dp.size()-1].begin(), dp[dp.size()-1].end());

}

int main()
{
    // vector<vector<int>> arr{{2},{3,4},{6,5,7},{4,1,8,3}};
    vector<vector<int>> arr{{-1},{3,2},{-3,1,-1}};
    cout<<minimumTotal(arr)<<endl;
}