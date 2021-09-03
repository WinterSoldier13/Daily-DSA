#include <bits/stdc++.h>
using namespace std;
#define lli long long int

class Solution{
public:
    vector<vector<int>> mem;

    void __init__()
    {
        mem = vector<vector<int>> (1000, vector<int> (1000, -1));
    }
    int recurse(string s, int i, string t, int j)
    {
        if(mem[i][j] != -1)
        {
            return mem[i][j]=mem[i][j];
        }
        if(j == 0)
        {
            return mem[i][j]=1;
        }
        if(i == 0)
        {
            return mem[i][j]=0;
        }

        if(s[i-1] == t[j-1])
        {
            return mem[i][j]=recurse(s, i-1, t, j-1) + recurse(s,i-1, t, j);
        }

        else
        {
            return mem[i][j]=recurse(s, i-1, t, j);
        }
    }
    int countWays(string S1, string S2)
    {
        __init__();
        return recurse(S1, S1.size(), S2, S2.size());
    }
};


int main()
{
    Solution ob;
    cout<<ob.countWays("geeksforgeeks", "gks")<<endl;
    return 0;
}