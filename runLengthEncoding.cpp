#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

class Solution
{
public:
    string solve(string s)
    {
        string out = "";
        int ptr1 = 0;
        int ptr2 = 0;

        while (ptr2 < s.size())
        {
            while (s[ptr1] == s[ptr2])
            {
                ptr2++;
            }
            out += to_string(ptr2 - ptr1);
            out += s[ptr1];
            ptr1 = ptr2;
        }

        // out += to_string(ptr2 - ptr1 + 1);
        // out += to_string(s[ptr1]);
        // ptr1 = ptr2;
        return out;
    }
};

int main()
{
    fast_cin();
    cin.tie(0);
    cout.tie(0);

    string s = "A";

    Solution ob;
    cout<<ob.solve(s)<<endl;
}