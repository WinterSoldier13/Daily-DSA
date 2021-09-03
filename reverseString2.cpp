#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tiii tuple<int, int, int>

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int l = s.length();
        int ptr1 = 0;
        vector<string> arr;
        for (int i = 0; i < l; i++)
        {
            if ((i + 1) % k == 0)
            {
                string temp = s.substr(ptr1, k);
                ptr1 += k;
                arr.push_back(temp);
            }
        }
        string temp = s.substr(ptr1, k);
        ptr1 += k;
        if (temp.size() != 0)
            arr.push_back(temp);

        for (int i = 0; i < arr.size(); i += 2)
        {
            reverse(arr[i].begin(), arr[i].end());
            // arr[i] = temp;
        }
        string out = "";
        for (auto x : arr)
            out += x;
        cout<<out<<endl;
        return out;
    }
};

int main()
{
    string s = "abcdef";
    int k = 2;

    Solution ob;
    ob.reverseStr(s, k);
}
