#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int



int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<vector<int>> arr(n, vector<int> (n));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }

        //print the triangle
        for(int i=0;i<n;i++)
        {
            int jIndex = i;
            int iIndex = 0;

            while (jIndex>=0 and iIndex<n)
            {
                cout<<arr[iIndex++][jIndex--]<<" ";
            }
        }

        //last part

        for(int i=1;i<n;i++)
        {
            int iIndex = i;
            int jIndex = n-1;

            while (jIndex >=1 and iIndex<n)
            {
                cout<<arr[iIndex++][jIndex--]<<" ";
            }
            
        }
        cout<<endl;
    }
    return 1;
}

