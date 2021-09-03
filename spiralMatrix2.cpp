#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tiii tuple<int, int, int, int>

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<int> t(n,0);
        vector<vector<int>> arr(n ,t);

        int count = 1;

        int c1 = 0;
        int c2 = n;
        int r1 = 0;
        int r2 = n;

        
        while(count<= n*n)
        {
            for(int i = c1; i<c2;i++)
            {
                arr[r1][i] = count++;
            }
            r1++;
            for(int i=r1;i<r2;i++)
            {
                arr[i][c2-1] = count++;
            }
            c2--;
            for(int i=c2-1;i>=c1;i--)
            {
                arr[r2-1][i] = count++;
            }
            r2--;
            for(int i=r2-1;i>=r1;i--)
            {
                arr[i][c1] = count++;
            }
            c1++;

        }

        for(auto x: arr)
        {
            for(auto c:x)
            {
                cout<<c<<" ";
            }
            cout<<endl;
        }
        return arr;
        
    }
};

int main()
{
    int n = 3;
    Solution ob;
    ob.generateMatrix(n);
}