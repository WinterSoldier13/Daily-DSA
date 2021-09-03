#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long int

int main()
{

    int t;
    scanf("%d", &t);

    while (t--)
    {
        ll n, k;
        scanf("%lld %lld",&n, &k);
        ll a[n + 1];
        map<ll, ll> mp;
        ll ans = 0, vc = 0, t = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll col[n + 1][n + 1] = {0};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                col[i][j] = 0;

        for (int i = 0; i < n; i++)
        {
            mp.clear();

            for (int j = i; j < n; j++)
            {
                col[i][j] = (j == 0) ? 0 : col[i][j - 1];
                if (mp.count(a[j]))
                {
                    if (mp[a[j]] == 1)
                    {
                        col[i][j]++;
                    }
                    col[i][j]++;
                }
                mp[a[j]]++;
            }
        }

        ans = 1e18;
        ll table = 100;
        ll dp[101][1001] = {0};
        for (int i = 0; i <= table; i++)
        {
            for (int j = 0; j <= n; j++)
                dp[i][j] = 0;
        }

        for (int i = 1; i < n + 1; i++)
        {
            dp[1][i] = col[0][i - 1];
        }

        for (int i = 1; i <= table; i++)
        {
            dp[i][1] = 0;
        }

        for (int i = 2; i <= table; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                ll bestval = 1e18;

                for (int p = 1; p < j; p++)
                {
                    bestval = min(bestval, dp[i - 1][p] + col[p][j - 1]);
                }
                dp[i][j] = bestval;
            }
        }

        for (table = 1; table <= 100; table++)
        {
            ans = min(table * k + dp[table][n], ans);
        }

        cout << ans << endl;
    }
    return 0;
}