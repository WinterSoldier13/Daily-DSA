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
#define MOD 1000000007
int fun(string &s)
{
    int acount = 0;
    int bcount = 0;
    int ccount = 0;

    for (auto x : s)
    {
        if (x == 'a')
            acount = (1 + ((acount)%MOD * 2)%MOD)%MOD;
        else if (x == 'b')
            bcount = (acount + ((bcount)%MOD * 2)%MOD)%MOD;
        else
        {
            ccount = (bcount + ((ccount)%MOD * 2)%MOD)%MOD;
        }
    }

    return ccount;
}

int main()
{
    return 0;
}