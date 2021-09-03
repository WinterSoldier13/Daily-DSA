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

string removeComments(string code)
{
    bool penDown = true;
    string out = "";

    int l = code.size();

    int ptr = 0;

    while (ptr < l)
    {
        char ch = code[ptr];

        if ((ch == '/' and code[ptr + 1] == '/') or (ch == '/' and code[ptr + 1] == '*'))
        {
            penDown = false;
            ptr += 2;
            continue;
        }
        if (!penDown and ((ch == '*' and code[ptr + 1] == '/') or (ch == '\\' and code[ptr + 1] == 'n')))
        {
            penDown = true;
            ptr += 2;
            continue;
        }

        if (penDown)
        {
            out += ch;
        }
        ptr++;
    }
    return out;
}

int main()
{
    fast_cin();

    return 0;
}