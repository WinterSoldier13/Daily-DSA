#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// s = ADOBECODEBANC
// t = abc
// out = banc

string minWindow(string s, string t)
{
    int sLength = s.size();
    int tLength = t.size();
    string out = s;

    int startIndex = -1;
    int ptr1 = 0;
    int count = 0;
    vector<int> hashS(sLength, 0);
    vector<int> hashT(tLength, 0);
    bool foundAtleastOnce = false;

    for (char ch : t)
    {
        hashT[ch]++;
    }

    for (int i = 0; i < sLength; i++)
    {
        char ch = s[i];

        hashS[ch]++;

        if (hashT[ch] != 0 and hashS[ch] <= hashT[ch])
        {
            count++;
        }

        if (count == tLength)
        {
            foundAtleastOnce = true;
            while (hashT[s[ptr1]] == 0 or hashS[s[ptr1]] > hashT[s[ptr1]])
            {

                if (hashS[s[ptr1]] > hashT[s[ptr1]])
                {
                    hashS[s[ptr1]]--;
                }
                ptr1++;
            }

            string curr = s.substr(ptr1, i - ptr1 + 1);
            if (curr.size() < out.size())
            {
                out = curr;
            }
        }
    }
    if (!foundAtleastOnce)
    {
        return "";
    }

    return out;
}

int main()
{
    string str = "ADOBECODEBANC";
    string pat = "a";

    cout << minWindow(str, pat) << endl;
}