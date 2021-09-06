#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        lli n, k;
        scanf("%lld %lld", &n, &k);
        lli totalSum = 0;
        pair<lli, lli> minPos= make_pair(INT32_MAX-1, -1);
        for (int i = 0; i < n; i++)
        {
            lli temp;
            scanf("%lld", &temp);
            if (temp < k)
            {
                if (k % temp == 0)
                {
                    lli moves = k/temp;
                    if(moves< minPos.first)
                    {
                        minPos = make_pair(moves, temp);
                    }
                }
            }
        }
        printf("%lld\n", minPos.second);
    }
}
