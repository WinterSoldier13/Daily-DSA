#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

void transpose(vector<vector<int>> &arr, int n)
{
    int l = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        bool flick = false;
        int count = 0;
        if (arr[0][1] == 2)
        {
            // along the row
            flick = false;
        }
        else
        {
            // along the col
            flick = true;
        }

        while (true)
        {
            if (flick == 1)
            {
                int l = 1;
                while (l < n and (arr[l][0] - arr[l - 1][0]) == 1)
                {
                    l++;
                }
                if (l >= n)
                {
                    count+=1;
                    break;
                }
                count++;
                transpose(arr, l);
                flick = !flick;
            }
            else
            {
                int l = 1;
                while (l < n and (arr[0][l] - arr[0][l - 1]) == 1)
                {
                    l++;
                }
                if (l >= n)
                {
                    break;
                }
                count++;
                transpose(arr, l);
                flick = !flick;
            }
        }

        printf("%d\n", count);
    }
}
