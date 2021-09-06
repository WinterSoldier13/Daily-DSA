#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
private:
    int count;

    void __init__()
    {
        count = 0;
    }

    void recurse(vector<vector<char>> &arr, int i, int j, string str, int index)
    {


        int rows = arr.size();
        int cols = arr[0].size();

        if (i < 0 or i >= rows or j < 0 or j >= cols or arr[i][j] == ' ' or arr[i][j] != str[index])
        {
            return;
        }
        if (index == str.size()-1)
        {
            count++;
            return;
        }
        char temp = arr[i][j];
        arr[i][j] = ' ';

        recurse(arr, i - 1, j, str, index + 1);
        recurse(arr, i, j + 1, str, index + 1);
        recurse(arr, i + 1, j, str, index + 1);
        recurse(arr, i, j - 1, str, index + 1);
        
        
        arr[i][j] = temp;
    }

public:
    int findOccurrence(vector<vector<char>> &arr, string target)
    {
        __init__();

        int rows = arr.size();
        int cols = arr[0].size();

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(arr[i][j] == target[0])
                {
                    recurse(arr, i, j, target, 0);
                }
            }
        }

        return count;
    }
};
