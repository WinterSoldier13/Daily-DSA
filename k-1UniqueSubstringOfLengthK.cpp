#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
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
#define endl '\n'

class Solution
{
private:
    vector<int> count;
    void __init__()
    {
        count = vector<int>(26, 0);
    }

    int getCountInCurrentWindow()
    {
        int sum = 0;
        for (auto x : count)
        {
            if (x != 0)
            {
                sum++;
            }
        }
        return sum;
    }
    void printChar(deque<char> dq)
    {
        while (!dq.empty())
        {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
    }
    int solve(string str, int k)
    {
        deque<char> dq;

        // get for the first window
        for (int i = 0; i < k; i++)
        {
            count[str[i] - 'a']++;
            dq.push_back(str[i]);
        }
        int ans = 0;
        for (int i = k; i < str.size(); i++)
        {
            // printChar(dq);
            int currentCount = getCountInCurrentWindow();
            if (currentCount == k - 1)
            {
                ans++;
            }
            char frontChar = dq.front();
            dq.pop_front();

            count[frontChar - 'a']--;

            dq.push_back(str[i]);
            count[str[i] - 'a']++;
        }
        int currentCount = getCountInCurrentWindow();
        if (currentCount == k - 1)
        {
            ans++;
        }

        return ans;
    }

public:
    int countOfSubstrings(string str, int k)
    {
        __init__();
        return solve(str, k);
    }
};

int main()
{
    fast_cin();

    string str = "aabab";
    int k = 3;

    Solution ob;
    cout << ob.countOfSubstrings(str, k) << endl;

    return 0;
}