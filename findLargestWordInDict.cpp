#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

int dynamic(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();

    vector<int> t(l2 + 1);
    vector<vector<int>> dp(l1 + 1, t);

    for (int i = 0; i <= l2; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= l1; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[l1][l2] == s2.size();
}

void myWay(vector<string> &arr, string s1)
{
    for (auto x : arr)
    {
        if (dynamic(s1, x))
        {
            cout << x << endl;
            return;
        }
    }
}

static int customSort(string s1, string s2)
{
    if (s1.size() > s2.size())
    {
        return 1;
    }
    else if (s1.size() == s2.size())
    {
        vector<string> temp{s1, s2};
        sort(temp.begin(), temp.end());

        return temp[0] == s1;
    }
    else
        return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        string s1;
        cin >> s1;

        sort(arr.begin(), arr.end(), customSort);

        myWay(arr, s1);
    }
}