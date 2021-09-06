#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<lli, int>

void recurse(vector<vector<char>> &arr, int i, int j, char old_, char new_)
{
    if (i < 0 or i >= arr.size() or j < 0 or j >= arr[0].size() or arr[i][j] != old_)
    {
        return;
    }
    arr[i][j] = new_;

    recurse(arr, i - 1, j, old_, new_);
    recurse(arr, i, j + 1, old_, new_);
    recurse(arr, i + 1, j, old_, new_);
    recurse(arr, i, j - 1, old_, new_);
    
}

void changeBoundry(vector<vector<char>> &arr)
{
    int rows = arr.size();
    int cols = arr[0].size();

    // top
    for(int i=0;i<cols;i++)
    {
        if(arr[0][i] == 'O')
        {
            recurse(arr, 0, i, 'O', 'A');
        }
    }
    // bottom
    for(int i=0;i<cols;i++)
    {
        if(arr[rows-1][i] == 'O')
        {
            recurse(arr, rows-1, i, 'O', 'A');
        }
    }
    // left
    for(int i=0;i<rows;i++)
    {
        if(arr[i][0] == 'O')
        {
            recurse(arr, i, 0, 'O', 'A');
        }
    }
    // right
    for(int i=0;i<rows;i++)
    {
        if(arr[i][cols-1] == 'O')
        {
            recurse(arr, i, cols-1, 'O', 'A');
        }
    }
}

void replaceOwithX(vector<vector<char>> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            if(arr[i][j] == 'O')
            {
                arr[i][j] = 'X';
            }
        }
    }
}
void replaceAwithO(vector<vector<char>> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            if(arr[i][j] == 'A')
            {
                arr[i][j] = 'O';
            }
        }
    }
}


int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int rows, cols;
        cin >> rows >> cols;

        vector<vector<char>> arr(rows, vector<char>(cols));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> arr[i][j];
            }
        }


        changeBoundry(arr);
        replaceOwithX(arr);
        replaceAwithO(arr);

        for(auto x: arr)
        {
            for(auto c: x)
            {
                cout<<c<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}