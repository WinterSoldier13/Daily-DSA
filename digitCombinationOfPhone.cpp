#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<string> mothership;

void backtracking(unordered_map<int, string> &hashmap, string s, string digits, int i)
{
    if (s.size() == digits.size())
    {
        mothership.push_back(s);
    }
    char curr = digits[i];

    for (char ch : hashmap[curr])
    {
        backtracking(hashmap, s + ch, digits, i + 1);
    }
}

vector<string> letterCombinations(string digits)
{
    unordered_map<int, string> hashmap;
    hashmap['2'] = "abc";
    hashmap['3'] = "def";
    hashmap['4'] = "ghi";
    hashmap['5'] = "jkl";
    hashmap['6'] = "mno";
    hashmap['7'] = "pqrs";
    hashmap['8'] = "tuv";
    hashmap['9'] = "wxyz";
    string s = "";
    backtracking(hashmap, s, digits, 0);

    return mothership;
}

int main()
{
    string digits = "234";

    vector<string> temp = letterCombinations(digits);
    for (auto c : temp)
    {
        cout << c << endl;
    }
}