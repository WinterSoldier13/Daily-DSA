#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

// https://practice.geeksforgeeks.org/problems/find-the-missing-no-in-string/1/?company[]=Intuit%20&company[]=Intuit%20&problemStatus=unsolved&page=1&query=company[]Intuit%20problemStatusunsolvedpage1company[]Intuit

void recurse(const string &str, int start, int &missingCount, string nextNumber, string &ans)
{
    if(missingCount > 1)
    {
        ans = "";
        missingCount = 0;
        return;
    }
    if (start >= str.size())
    {
        return;
    }
    int nextNumberSize = nextNumber.size();
    int nextNumberInt = stoi(nextNumber);

    int next2nextNumberIn = nextNumberInt + 1;
    string next2nextNumber = to_string(next2nextNumberIn);
    int next2nextNumberSize = next2nextNumber.size();

    string next2next2nextNumber = to_string(next2nextNumberIn + 1);

    string possibleNextNumber = str.substr(start, nextNumberSize);
    int possibleNextNumberInt = stoi(possibleNextNumber);

    string possibleNext2NextNumber = str.substr(start, next2nextNumberSize);
    int possibleNext2NextNumberInt = stoi(possibleNext2NextNumber);

    if (possibleNextNumberInt == nextNumberInt)
    {
        recurse(str, start + nextNumberSize, missingCount, next2nextNumber, ans);
    }
    else if (possibleNext2NextNumberInt == next2nextNumberIn)
    {
        missingCount++;
        ans = nextNumber;
        recurse(str, start + next2nextNumberSize, missingCount, next2next2nextNumber, ans);
    }
    else
    {
        ans = "";
        missingCount = 0;
        return;
    }
    
}

int missingNumber(const string &str)
{
    bool ansFound = false;
    int missingCount;

    for (int i = 1; i <= 6; i++)
    {
        string num = str.substr(0, i);
        int n = stoi(num);
        int np1 = n + 1;
        string nextNumber = to_string(np1);
        missingCount = 0;
        string ans = "";
        recurse(str, i, missingCount, nextNumber, ans);

        if (missingCount)
        {
            return stoi(ans);
        }
    }
    return -1;
}

int main()
{
    fast_cin();

    getT()
    {
        string s;
        cin >> s;

        cout << missingNumber(s) << endl;
    }

    return 0;
}