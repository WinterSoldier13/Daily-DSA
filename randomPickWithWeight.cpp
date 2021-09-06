#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

class Solution
{
public:
    vector<int> cummulativeFreq;

    Solution(vector<int> &w)
    {
        vector<int> temp(w.size());
        cummulativeFreq = temp;
        cummulativeFreq[0] = w[0];
        for (int i = 1; i < w.size(); i++)
        {
            cummulativeFreq[i] = w[i] + cummulativeFreq[i - 1];
        }
    }

    int pickIndex()
    {
        int num = 1 + rand() % cummulativeFreq[cummulativeFreq.size() - 1];
        int index = 0;
        for (auto x : cummulativeFreq)
        {
            if (num < x)
            {
                return index;
            }
            index++;
        }
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */