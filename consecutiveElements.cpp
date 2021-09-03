#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        string out = "";

        for (auto x : s)
        {
            if (out.size() == 0)
            {
                out += x;
                continue;
            }
            if (out[out.size() - 1] == x)
            {
                continue;
            }
            out += x;
        }
        cout << out << endl;
    }
}