#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void combinations(string s, int i, string t)
{
    if (i == s.size() - 1)
    {
        cout << t << endl;
        t += s[i];
        cout << t << endl;
        return;
    }
    combinations(s, i + 1, t);
    t += s[i];
    combinations(s, i + 1, t);
}

vector<vector<int>> mothership;

int k;

void printCombinations(vector<int> arr, int i, vector<int> support)
{
    if (i == arr.size() - 1)
    {

        mothership.push_back(support);
        support.push_back(arr[i]);
        mothership.push_back(support);

        return;
    }
    vector<int> temp = support;
    temp.push_back(arr[i]);

    printCombinations(arr, i + 1, support);
    printCombinations(arr, i + 1, temp);
}

unordered_set<string> hashset;
void getArrangements(string str, int i, string temp)
{
     if (i == str.size() - 1)
    {
        if(temp!="")
        hashset.insert(temp);
        temp+=(str[i]);
        mothership.insert(temp);
        return;
    }

    string t = temp;
    t+=(str[i]);

    getArrangements(arr, i + 1, t);
    getArrangements(arr, i + 1, temp);
}
int main()
{
    string str = "ABCD";
    string temp = "";
    getArrangements(str, 0, temp);
    cout<<hashset.size()<<endl;
}

int main()
{
    // string s = "abc";
    // string t="";
    // combinations(s,0,t);

    vector<int> temp;
    vector<int> arr{1, 2, 3};
    printCombinations(arr, 0, temp);
    for (auto x : mothership)
    {
        for (int c : x)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}