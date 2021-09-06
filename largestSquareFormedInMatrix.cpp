#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define ll unsigned long long int

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        ll arr[n][m];
        ll dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        ll maxx = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                dp[i + 1][j + 1] = arr[i][j];

                if (arr[i][j] == 1)
                    maxx = 1;
            }
        }

        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                ll a = dp[i - 1][j], b = dp[i - 1][j - 1], c = dp[i][j - 1];

                if (dp[i][j] == 0)
                    continue;

                ll minn = min(a, min(b, c));
                dp[i][j] = (minn + 1);
                maxx = max(dp[i][j], maxx);
            }
        }
        cout << maxx << "\n";
    }
    return 0;
}