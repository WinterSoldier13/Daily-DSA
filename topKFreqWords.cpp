#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    struct Compare
    {
        bool operator()(pair<int, string> &p1, pair<int, string> &p2)
        {
            int p1Count = p1.first;
            string p1Word = p1.second;
            int p2Count = p2.first;
            string p2Word = p2.second;

            if (p1Count < p2Count)
            {
                return true;
            }
            else if (p1Count == p2Count)
            {
                return p1Word > p2Word;
            }
            else
                return false;
            return false;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> hashmap;

        for (auto word : words)
        {
            hashmap[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int,string>>, Compare > maxHeap;

        for (auto it = hashmap.begin(); it != hashmap.end(); it++)
        {
            maxHeap.push({it->second, it->first});
        }
        vector<string> out;
        int prevCount = -1;

        while (!maxHeap.empty() and k--)
        {
            auto top = maxHeap.top();
            int currCount = top.first;
            string currWord = top.second;

            out.push_back(currWord);
            maxHeap.pop();
        }
        return out;
    }
};

int main()
{
    vector<string> arr{"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    Solution ob;
    auto out = ob.topKFrequent(arr, k);
    for (auto x : out)
    {
        cout << x << endl;
    }
    return 1;
}