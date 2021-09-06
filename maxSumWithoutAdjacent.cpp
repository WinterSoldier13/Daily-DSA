#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<stdio.h>

using namespace std;

int maxSum(vector<vector<int>> grid)
{
    int n = grid[0].size();
    // Sum including maximum element of first column 
    int incl = max(grid[0][0], grid[1][0]); 
  
    // Not including first column's element 
    int excl = 0, excl_new; 
  
    // Traverse for further elements 
    for (int i = 1; i<n; i++ ) 
    { 
        // Update max_sum on including or excluding 
        // of previous column 
        excl_new = max(excl, incl); 
  
        // Include current column. Add maximum element 
        // from both row of current column 
        incl = excl + max(grid[0][i], grid[1][i]); 
  
        // If current column doesn't to be included 
        excl = excl_new; 
    } 
  
    // Return maximum of excl and incl 
    // As that will be the maximum sum 
    return max(excl, incl); 
}





int main()
{
    vector<vector<int>> arr{{31, 83, 65, 30, 15},
                            {66, 89, 0, 43, 15}};

    cout<<maxSum(arr)<<endl;

    return 0;
}