#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

lli min_;
lli recurse(lli a, lli b)
{
    if (a == b)
    {
        return 0;
    }

    lli count = 0;
    int num = 10;

    lli val = abs(a-b);

    while (val!=0)
    {
        count+=val/num;
        val%=num;
        while (num>val and num!=0)
        {
            num--;
        }
        
    }
    

    return count;
}

int main()
{
    int t;
    scanf("%d", &t);
    lli a, b;

    while (t--)
    {
        scanf("%lld %lld", &a, &b);

        if (a == b)
        {
            printf("0\n");
            continue;
        }

        lli ans = recurse(a, b);
        printf("%lld\n", ans);
    }
}