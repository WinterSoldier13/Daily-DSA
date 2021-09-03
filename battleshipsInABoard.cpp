#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    int countBattleships(vector<vector<char>> &arr)
    {
        int rows = arr.size();
        int cols = arr[0].size();
        if (rows == 0 or cols == 0)
        {
            return 0;
        }

        int top, left;
        int count = 0;
        for(int i=0;i<rows;i++)
        {
            top = i-1;
            for(int j = 0;j<cols;j++)
            {
                left = j-1;
                if(arr[i][j]=='X' and (top<0 or arr[top][j]!='X') and (left<0 or arr[i][left]!='X'))
                {
                    count++;
                }
            }
        }
        return count;
    }
};