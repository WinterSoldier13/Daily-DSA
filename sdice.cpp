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
#define lli long long int
#define pii pair<int, int>
#define MOD 1e9 + 7
#define ll lli

class Solution
{
public:
    Solution()
    {
    }
    void solve(lli n)
    {
        unordered_map<int, pair<int, int>> hashmap;
        hashmap[5] = {6 + 5 + 4 + 3 + 2, 2};
        hashmap[4] = {6 + 5 + 4 + 3, 3};
        hashmap[3] = {6 + 5 + 4, 4};
        hashmap[2] = {6 + 5, 5};

        lli mul = n / 4;
        lli remainder = n % 4;

        lli totalSum = 0;
        lli i;
        // for (i = 1; i < mul; i++)
        // {
        //     totalSum += (hashmap[2].first * 4);
        // }

        if(mul>1)
        {
            totalSum+= (mul-1)*(hashmap[2].first * 4);
        }
        // if (i == mul)
        //     totalSum += (hashmap[3].first * 4);

        if(mul !=0)
        {
            totalSum+= (hashmap[3].first*4);
        }

        if (remainder == 1)
        {
            if (totalSum != 0)
            {
                totalSum -= 4;
            }
            totalSum += hashmap[5].first;
        }
        else if (remainder == 2)
        {
            if (totalSum != 0)
            {
                totalSum -= 8;
            }
            totalSum += (hashmap[4].first * 2);
        }
        else if (remainder == 3)
        {
            if (totalSum != 0)
            {
                totalSum -= 12;
            }
            totalSum += (hashmap[4].first * 2 + hashmap[3].first);
        }

        cout << totalSum << endl;
    }
};

int main()
{
    fast_cin();
    Solution ob;

    getT()
    {
        lli n;
        cin >> n;

        ob.solve(n);
    }
    return 0;
}