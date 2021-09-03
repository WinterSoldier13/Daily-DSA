#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

void solve(lli n)
{
    string s = "";
    bool seen1 = false;
    int count = 0;
    int position = 0;
    while (n != 0)
    {
        int curr = n & 1;
        if (curr == 1 and seen1)
        {
            cout << "NO" << endl;
            return;
        }
        if (curr == 1)
        {
            seen1 = true;
            position = count;
        }
        n = n >> 1;
        count++;
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        if (n == 1)
        {
            cout << "YES" << endl;
            continue;
        }

        if (n == 0)
        {
            cout << "NO" << endl;
            continue;
        }

        solve(n);
    }
}
// 00000000
// 00000010
