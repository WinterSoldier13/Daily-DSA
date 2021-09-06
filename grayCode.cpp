#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

class Solution
{
public:
    unordered_map<int, vector<string>> hashmap;

    Solution()
    {
        vector<string> arr{"0", "1"};
        hashmap[1] = arr;
    }

    int findMinAlreadyThere(int n)
    {
        for (int i = n - 1; i >= 1; i--)
        {
            if (hashmap.find(i) != hashmap.end())
            {
                return i;
            }
        }
        return -1;
    }

    void generateFromNminusOne(int n)
    {
        vector<string> prevList;

        int lastIndex = findMinAlreadyThere(n);

        for (int i = lastIndex + 1; i <= n; i++)
        {
            vector<string> lastArr = hashmap[i - 1];
            vector<string> reverseLastArr = lastArr;

            reverse(reverseLastArr.begin(), reverseLastArr.end());

            int l = lastArr.size();

            for (int i = 0; i < l; i++)
            {
                lastArr[i] = "0" + lastArr[i];
            }
            for (int i = 0; i < l; i++)
            {
                reverseLastArr[i] = "1" + reverseLastArr[i];
            }
            vector<string> ans;
            for (auto x : lastArr)
                ans.push_back(x);
            for (auto x : reverseLastArr)
                ans.push_back(x);

            hashmap[i] = ans;
        }
    }
    vector<string> graycode(int n)
    {
        if (hashmap.find(n) != hashmap.end())
        {
            return hashmap[n];
        }
        generateFromNminusOne(n);
        for (auto x : hashmap[n])
            cout << x << " ";
        cout << endl;
        return hashmap[n];
    }
};

int main()
{
    int n = 2;
    Solution ob;

    ob.graycode(2);
    ob.graycode(3);
    ob.graycode(5);
    return 0;
}