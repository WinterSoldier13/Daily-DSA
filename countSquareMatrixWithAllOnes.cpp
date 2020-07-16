#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>>& arr)
{
    int rows = arr.size();
    int cols = arr[0].size();

    vector<int> t(cols, -1);
    vector<vector<int>> dp(rows, t);

    for(int i=0;i<cols;i++)
    {
        dp[0][i] = arr[0][i];
    }
    for(int i=0;i<rows;i++)
    {
        dp[i][0] = arr[i][0];
    }

    for(int i=1;i<rows;i++)
    {
        for(int j=1;j<cols;j++)
        {
            if(arr[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
        }
    }
    int totalPossible = 0;

    for(auto x:dp)
    {
        for(auto c:x)
        {
            cout<<c<<" ";
            totalPossible+=c;
        }
        cout<<endl;
    }
    return totalPossible;  
}

int main()
{
    vector<vector<int>> arr{{0,1,1,1},
                            {1,1,1,1},
                            {0,1,1,1}};

    cout<<countSquares(arr)<<endl;


}
