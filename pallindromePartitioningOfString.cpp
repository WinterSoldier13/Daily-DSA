#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution
{
private:
    vector<vector<string>> mothership;

    bool isPallindrome(string &str, int start, int end)
    {
        while (start < end)
        {
            if (str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void recurse(string &str, int start, int end, vector<string> &res)
    {
        if (start > end)
        {
            mothership.push_back(res);
            return;
        }

        for (int k = start; k <= end; k++)
        {
            if (isPallindrome(str, start, k))
            {
                res.push_back(str.substr(start, k - start+1 ));
                recurse(str, k + 1, end, res);
                res.pop_back();
            }
        }
    }

    void printMothership()
    {
        for (auto x : mothership)
        {
            for (auto c : x)
            {
                cout << c << " ";
            }
            cout << endl;
        }
    }

public:
    vector<vector<string>> getGray(string S)
    {
        mothership.clear();
        vector<string> res;
        recurse(S, 0, S.size() - 1, res);
        printMothership();
        return mothership;
    }
};

int main()
{
    string s = "madam";

    Solution ob;
    ob.getGray(s);
    return 0;
}