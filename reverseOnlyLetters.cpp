#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int l = s.size();
        vector<char> arr(l, '\\');

        for (int i = 0; i < l; i++)
        {
            if (!isalpha(s[i]))
            {
                arr[i] = s[i];
            }
        }
        reverse(s.begin(), s.end());

        int ptr1 = 0;
        int ptr2 = 0;
        while (ptr1 < l and ptr2 < l)
        {
            if (!isalpha(s[ptr2]))
            {
                ptr2++;
                continue;
            }
            if (arr[ptr1] != '\\')
            {
                ptr1++;
                continue;
            }
            else
            {
                arr[ptr1] = s[ptr2];
                ptr1++;
                ptr2++;
            }
        }
        string ans = "";
        for (auto x : arr)
        {
            ans += x;
        }
        return ans;
    }
};

int main()
{
    string s = "Test1ng-Leet=code-Q!";

    Solution ob;
    cout << ob.reverseOnlyLetters(s) << endl;
    ;
}
