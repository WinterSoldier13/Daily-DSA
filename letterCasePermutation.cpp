#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tup tuple<int, int>

class Solution
{
public:
    vector<string> mothership;
    void recurse(string s, int index)
    {
        if (index == s.size())
        {
            mothership.push_back(s);
            return;
        }
        if (isdigit(s[index]))
        {
            recurse(s, index + 1);
        }
        else
        {
            s[index] = tolower(s[index]);
            recurse(s, index + 1);
            s[index] = toupper(s[index]);
            recurse(s, index + 1);
        }
    }
    vector<string> letterCasePermutation(string S)
    {
        mothership.clear();
        recurse(S, 0);

        return mothership;
    }
};