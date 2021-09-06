#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int expandFromMiddle(string &s, int l, int r)
    {
        if(s=="" or l>r)
            return 0;
        
        while(l>=0 and r<s.size() and s[l] == s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
    }
    
    string longestPalindrome(string s) 
    {
        int start =0;
        int end =0;
        
        if(s.size()<=1)
        {
            return s;
        }
        
        for(int i=0;i<s.size();i++)
        {
            int len1 = expandFromMiddle(s, i,i);
            int len2 = expandFromMiddle(s, i, i+1);
            
            int len = max(len1, len2);
            
            if(len> end-start + 1)
            {
                start = i - (len-1)/2;
                end = i+ len/2;
            }
        }
        
        return s.substr(start, end-start+1);
        
        
    }
};

int main()
{
    Solution ob;
    cout<<ob.longestPalindrome("mactacocatbook")<<endl;
}