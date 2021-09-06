#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)

class Solution 
{
    public:
    bool oneApproach(string s1, string s2)
    {
        int ptr1 = 0;
        int l1 = s1.size();
        
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i] == s1[ptr1])
            {
                ptr1++;
            }
            if(ptr1 == l1)
            {
                return 1;
            }
        }
        return 0;
    }
    bool solve(string s1, string s2) 
    {
        if(s1.size() == 0 and s2.size() == 0)
        {
            return 1;
        }
        if(s1.size() == 0 or s2.size() == 0)
        {
            return 0;
        }
        int l = dynamic(s1, s2);

        return l == s2.size();
    }
};

int main()
{
    fast_cin();
    cin.tie(0);
    cout.tie(0);


}