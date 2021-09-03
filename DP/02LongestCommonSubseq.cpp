#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

//LONGEST COMMON SUBSEQUENCE

// ABCDGH and AEDFHR => ADH => len=3

// RECURSIVE

int lcs(string s1, string s2, int p1, int p2)
{
    if (p1 == 0 or p2 == 0) // if lenght of either is zero then their is no common subsequence possible
    {
        return 0;
    }
    if (s1[p1 - 1] == s2[p2 - 1])
    {
        return 1 + lcs(s1, s2, p1 - 1, p2 - 1);
    }
    else
    {
        return max(lcs(s1, s2, p1, p2 - 1), lcs(s1, s2, p1 - 1, p2));
    }
}

//DYNAMIC

int dynamic(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    // NOW from the recursive we can see that two variables are changing p1 and p2
    // Hence our DP will be 2D

    int dp[l1 + 1][l2 + 1];

    //NOW init with the base cases here in the dp

    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            if (i == 0 or j == 0)
            {
                dp[i][j] = 0;
            }
        }
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

    //Printing the seq

    int i = l1, j = l2;
    string str = "";
    while (i > 0 && j > 0)
    {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (s1[i - 1] == s2[j - 1])
        {
            str += s1[i - 1]; // Put current character in result
            i--;
            j--; // reduce values of i, j and index
        }

        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(str.begin(), str.end());
    cout << str << endl;

    return dp[l1][l2];
}

int main()
{
    // string s1 = "AGXTXXAYGAB";
    // string s2 = "GXTXAYBX";
    string s1 = "bb";
    string s2 = "ahbgdc";
    int l1 = s1.size();
    int l2 = s2.size();

    cout << lcs(s1, s2, l1, l2) << endl;
    cout << dynamic(s1, s2) << endl;
}