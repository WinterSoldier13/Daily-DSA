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
        int n;
        scanf("%d", &n);

        string s = "";

        for (int i = 0; i < 8; i++)
        {
            int d = n&1;
            s += (d + '0');
            n = n >> 1;
        }
        reverse(s.begin(), s.end());

        string part1 = s.substr(0, 4);
        string part2 = s.substr(4);

        string newS = part2 + part1;

        // cout << s << " " << newS << endl;
        reverse(newS.begin(), newS.end());
        int count = 0;
        int sum_ = 0;
        for (int i = 0; i < 8; i++)
        {
            char ch = newS[i];
            if (ch == '1')
            {
                sum_ += pow(2, count);
            }
            count++;
        }

        cout << sum_ << endl;
    }
}