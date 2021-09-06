#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &arr)
    {
        int l = arr.size();
        if (l == 0 or l == 1)
        {
            return arr;
        }
        sort(arr.begin(), arr.end());
        vector<int> count(l, 1);

        for (int i = 1; i < l; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0)
                {
                    // using assosiative law
                    count[i] = max(count[i], count[j] + 1);
                }
            }
        }

        vector<int> out;

        int maxCount = *max_element(count.begin(), count.end());
        
        int maxIndex = 0;
        for(int i=0;i<l;i++)
        {
            if(count[i] == maxCount)
            {
                maxIndex = i;
                
            }
        }
        
        int ele = arr[maxIndex];
        for(int i = maxIndex;i >= 0; i--)
        {
            if(ele % arr[i]==0 and count[i] == maxCount)
            {
                out.push_back(arr[i]);
                ele = arr[i];
                maxCount--;
            }
        }
        return out;
    }
};

