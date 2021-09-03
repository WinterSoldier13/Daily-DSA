#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void transpose(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    for(int i=0;i<rows;i++)
    {
        for(int j=i;j<rows;j++)
        {
            if(i==j)
            {
                continue;
            }
            else
            {
                swap(grid[i][j], grid[j][i]);
            }
            

        }
    }
}

void mirror(vector<vector<int>> &grid)
{
    int n = grid.size();
    int mid = n/2;

    for(int i =0;i<n;i++)
    {
        for(int j=0;j<mid;j++)
        {
            swap(grid[i][j], grid[i][n-j-1]);
        }
    }
}



void rotateImage(vector<vector<int>> &grid)
{
    transpose(grid);
    mirror(grid);


}

void printGrid(vector<vector<int>>&grid)
{
    for(auto x: grid)
    {
        for(auto c:x)
        cout<<c<<" ";
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> grid{{1,2,3,4},
                             {5,6,7,8},
                             {9,10,11,12},
                             {13,14,15,16}};

    rotateImage(grid);

    printGrid(grid);

}