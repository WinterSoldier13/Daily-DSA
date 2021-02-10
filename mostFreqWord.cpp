#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

string mostFrequentWord(string arr[], int n)
{
    unordered_map<string, int> hashmap;

    for (int i = 0; i < n; i++)
    {
        hashmap[arr[i]]++;
    }

    priority_queue<pair<int, string>> pq;

    for (auto it = hashmap.begin(); it != hashmap.end(); it++)
    {
        pq.push({it->second, it->first});
    }

    unordered_set<string> candidates;

    int maxS = 0;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        if (top.first >= maxS)
        {

            candidates.insert(top.second);
            maxS = top.first;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (candidates.size() == 1)
        {
            break;
        }
        if (candidates.count(arr[i]))
        {
            candidates.erase(arr[i]);
        }
    }

    auto it = candidates.begin();

    return *it;
}

int main()
{
    string arr[] = {"budxdu", "budxdu", "akfwn", "akfwn", "budxdu", "akfwn", "suoko", "akfwn", "budxdu", "dhxeg", "suoko", "akfwn", "dhxeg"};
    int n = 13;

    cout << mostFrequentWord(arr, n) << endl;
    return 0;
}