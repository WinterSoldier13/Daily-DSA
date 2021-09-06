#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    int isScramble(string S1, string S2)
    {
        // Strings of non-equal length
        // cant' be scramble strings
        if (S1.length() != S2.length())
        {
            return 0;
        }

        int n = S1.length();

        // Empty strings are scramble strings
        if (n == 0)
        {
            return 1;
        }

        // Equal strings are scramble strings
        if (S1 == S2)
        {
            return 1;
        }

        // Check for the condition of anagram
        string copy_S1 = S1, copy_S2 = S2;

        sort(copy_S1.begin(), copy_S1.end());
        sort(copy_S2.begin(), copy_S2.end());

        if (copy_S1 != copy_S2)
        {
            return 0;
        }

        for (int i = 1; i < n; i++)
        {

            // Check if S2[0...i] is a scrambled
            // string of S1[0...i] and if S2[i+1...n]
            // is a scrambled string of S1[i+1...n]
            if (isScramble(S1.substr(0, i), S2.substr(0, i)) && isScramble(S1.substr(i, n - i),
                                                                           S2.substr(i, n - i)))
            {
                return 1;
            }

            // Check if S2[0...i] is a scrambled
            // string of S1[n-i...n] and S2[i+1...n]
            // is a scramble string of S1[0...n-i-1]
            if (isScramble(S1.substr(0, i),
                           S2.substr(n - i, i)) &&
                isScramble(S1.substr(i, n - i),
                           S2.substr(0, n - i)))
            {
                return 1;
            }
        }

        // If none of the above
        // conditions are satisfied
        return 0;
    }
};