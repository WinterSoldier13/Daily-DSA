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

class Solution
{
private:
    int isPrime(int num)
    {
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0)
                return 0;
        return 1;
    }
    vector<int> mat;
    void fillMat()
    {
        mat = vector<int>(10001, 0);
        for (int i = 1; i < 10000; i++)
        {
            mat[i] = isPrime(i);
        }
    }
    vector<vector<int>> graph;
    void makeGraph()
    {
        graph = vector<vector<int>>(10000);
        for (int i = 1000; i < 10000; i++)
        {
            if (mat[i])
            {
                string num = to_string(i);
                for (int j = 0; j < 4; j++)
                {
                    char ch = num[j];

                    for (char x = '0'; x <= '9'; x++)
                    {
                        if (x == ch)
                            continue;
                        string temp = num;
                        temp[j] = x;
                        if (mat[stoi(temp)] and temp.size() == 4)
                        {
                            graph[stoi(num)].push_back(stoi(temp));
                            graph[stoi(temp)].push_back(stoi(num));
                        }
                    }
                }
            }
        }
    }

    void printGraph()
    {
        int index = 0;
        for (auto x : graph)
        {
            cout << index++ << " : ";
            for (auto c : x)
                cout << c << " ";
            cout << endl;
        }
    }

    int bfs(int num1, int num2)
    {
        queue<int> q;
        int minPath = INT_MAX;

        q.push(num1);
        unordered_set<int> track;
        track.insert(num1);
        bool found = false;
        int count = 0;
        while (!q.empty())
        {
            int l = q.size();
            count++;
            // cout << endl;
            for (int i = 0; i < l; i++)
            {
                auto curr = q.front();
                q.pop();

                if (curr == num2)
                {
                    // cout << "found" << curr << endl;
                    found = true;
                    break;
                }
                for (auto node : graph[curr])
                {
                    if (track.count(node) == 0)
                    {
                        track.insert(node);
                        // cout << node << endl;
                        q.push(node);
                    }
                }
            }
            if (found)
                break;
        }
        if (found == false)
            return -1;
        return count;
    }

public:
    int solve(int num1, int num2)
    {
        if (num1 == num2)
        {
            return 0;
        }
        fillMat();
        makeGraph();
        // printGraph();
        return bfs(num1, num2) - 1;
    }
};

int main()
{
    fast_cin();
    int n1, n2;
    cin >> n1 >> n2;

    Solution ob;

    cout << ob.solve(n1, n2) << endl;

    return 0;
}