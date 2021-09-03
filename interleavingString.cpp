#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

vector<vector<int>> mem;

void __init__(int m, int n)
{
    vector<int> t(n + 1, -1);
    vector<vector<int>> temp(m + 1, t);
    mem = temp;
}
int recurse(string s1, string s2, string s3, int i, int j, int k)
{
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    if (i == s1.size() and j == s2.size() and k == s3.size())
    {
        return mem[i][j] = 1;
    }
    int res = 0;
    if (i < s1.size())
    {
        if (s1[i] == s3[k])
        {
            res = res or recurse(s1, s2, s3, i + 1, j, k + 1);
        }
    }
    if (j < s2.size())
    {
        if (s2[j] == s3[k])
        {
            res = res or recurse(s1, s2, s3, i, j + 1, k + 1);
        }
    }

    return mem[i][j] = res;
}

int isInterleave(string s1, string s2, string s3)
{
    __init__(s1.size(), s2.size());

    return (recurse(s1, s2, s3, 0, 0, 0));
}

int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    cout << isInterleave(s1, s2, s3) << endl;
}
