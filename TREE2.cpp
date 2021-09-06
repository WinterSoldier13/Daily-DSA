#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);
        unordered_set<lli> hashset;

        for(int i=0;i<n;i++)
        {
            lli temp;
            scanf("%lld", &temp);
            hashset.insert(temp);
        }
        if(!hashset.count(0))
        printf("%lld\n", (lli)hashset.size());
        else
        printf("%lld\n", (lli)hashset.size()-1);

    }
}

