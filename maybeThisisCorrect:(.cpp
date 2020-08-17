#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

int isIncreasing(string s)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] > s[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
int isDecreasing(string s)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] < s[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int mcm(string s)
{
    int l = s.size();
    if (l == 0)
    {
        return 0;
    }
    if (isIncreasing(s) or isDecreasing(s))
    {
        return 1;
    }
    int min_ = INT32_MAX;

    for (int i = 1; i < l; i++)
    {
        int count = mcm(s.substr(0, i)) + mcm(s.substr(i));
        min_ = min(min_, count);
    }
    return min_;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << mcm(s) << endl;
    }
}
