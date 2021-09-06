#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
#include <stdio.h>

using namespace std;

void remove(string &s, int index, string &newString)
{
    if (index >= s.size())
    {
        return;
    }
    if (index < s.size() - 1 and s[index] == s[index + 1])
    {
        remove(s, index + 1, newString);
    }
    else if (index > 0 and s[index] == s[index - 1])
    {
        remove(s, index + 1, newString);
    }
    else
    {
        newString += s[index];
        remove(s, index + 1, newString);
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        string newString = "";
        remove(s, 0, newString);
        s = newString;

        while (true)
        {
            string temp = "";
            remove(newString, 0, temp);

            newString = temp;
            if (newString == s)
            {
                break;
            }
            s = newString;
        }

        cout << newString << endl;
    }
}