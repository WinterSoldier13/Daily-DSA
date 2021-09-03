#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli long long int
#define pii pair<int, int>
#define endl '\n'
#define printArr(arr)     \
    for (auto x : arr)    \
        cout << x << " "; \
    cout << endl;
#define printHashmap(hashmap)                                  \
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) \
    {                                                          \
        cout << it->first << " " << it->second << endl;        \
    }
#define print2DArray(arr)     \
    for (auto x : arr)        \
    {                         \
        for (auto c : x)      \
            cout << c << " "; \
        cout << endl;         \
    }

// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________

class Solution
{
public:
    int leastInterval(vector<char> &arr, int n)
    {
        unordered_map<char, int> hashmap;
        for (auto x : arr)
            hashmap[x]++;

        priority_queue<pair<int, char>> pq;
        unordered_map<int, pair<int, char>> waitingQ;

        for (auto x : hashmap)
            pq.push({x.second, x.first});

        vector<char> out;
        int time = 0;
        while(!pq.empty() or !waitingQ.empty())
        {
            // check if there is any task in the waitingQ
            if(waitingQ.find(time-n-1) != waitingQ.end())
            {
                pq.push(waitingQ[time-n-1]);
                waitingQ.erase(time-n-1);
            }

            if(!pq.empty())
            {
                auto curr = pq.top();
                pq.pop();
                curr.first--;

                if(curr.first != 0)
                    waitingQ[time] = curr;

                out.push_back(curr.second); 
            }
            else
            {
                out.push_back('#');
            }

            time++;
        }

        int count = 0;
        for (auto x : out)
            if(x == '#') count++;
        // cout << endl;

        return count;
    }
};

int main()
{
    vector<char> arr{'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    Solution ob;
    ob.leastInterval(arr, n);

    return 0;
}