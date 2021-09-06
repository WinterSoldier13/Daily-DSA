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

class Solution
{
private:
    unordered_set<int> hashset;

public:
    Solution()
    {
        hashset.clear();
    }
    void recurse(int currentNumber, int lowerBound, int upperBound)
    {
        if (currentNumber <= upperBound and currentNumber >= lowerBound)
            hashset.insert(currentNumber);

        int lastD = currentNumber % 10;

        int newNum1, newNum2;

        if (lastD == 0)
        {
            newNum1 = currentNumber * 10 + 1;
            if ( newNum1 <= upperBound)
            {
                recurse(newNum1, lowerBound, upperBound);
            }
        }
        else if (lastD == 9)
        {
            newNum1 = currentNumber * 10 + 8;
            if (newNum1 <= upperBound)
            {
                recurse(newNum1, lowerBound, upperBound);
            }
        }
        else
        {
            newNum1 = currentNumber * 10 + (lastD - 1);
            if ( newNum1 <= upperBound)
            {
                recurse(newNum1, lowerBound, upperBound);
            }
            newNum2 = currentNumber * 10 + (lastD + 1);
            if ( newNum2 <= upperBound)
            {
                recurse(newNum2, lowerBound, upperBound);
            }
        }
    }

    int steppingNumbers(int n, int m)
    {
        hashset.clear();
        for (int i = 0; i <= 9; i++)
        {
            recurse(i, n, m);
        }

        for (auto it = hashset.begin(); it != hashset.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        return hashset.size();
    }
};

int main()
{
    fast_cin();
    int n, m;
    cin >> n >> m;

    Solution ob;
    ob.steppingNumbers(n, m);
    return 0;
}