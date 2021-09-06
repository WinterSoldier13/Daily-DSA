#include <iostream>
#include <bits/stdc++.h>
#include<cstring>
#include<stdio.h>

using namespace std;



// BASE RECURSION BASED APPROACH
int longestCommonSubstring(string s1, string s2, int i, int j)
{
    if(i == 0 or j ==0)
    {
        return 0;
    }
    if(s1[i-1] == s2[j-1])
    {
        return 1+ longestCommonSubstring(s1,s2,i-1,j-1);

    }
    else
    {
        return max(longestCommonSubstring(s1, s2 ,i,j-1), longestCommonSubstring(s1,s2,i-1,j));
    }
    
}

// Okay so the basic Idea is the number of deletions in a string to make a pallindrome = no of insertions to make a pallindrome
// First find the longest Pallindromic Subseq... by comparing the string to its reverse using longestCommonSubseq
// The length of the string minus the length of the longest pallindromic subsequence will give you the min no of deletions


int dynamicLongestPallindroimicSubsequence(string s)
{
    string revS = s;
    reverse(revS.begin(), revS.end());

    int l = s.size();

    int dp[l+1][l+1];

    for(int i=0;i<=l;i++)
    {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }

    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=l;j++)
        {
            if(s[i-1] == revS[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
            
        }
    }
    int longestPallindromicSubseq = dp[l][l];

    return (l-longestPallindromicSubseq);
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        cout<<dynamicLongestPallindroimicSubsequence(s)<<endl;



    }
}