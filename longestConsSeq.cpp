#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int> &arr)
{
    if (arr.size() == 0)
        return 0;
    if (arr.size() == 1)
        return 1;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto c : arr)
        pq.push(c);

    int maxL = 1;
    int lenSoFar = 1;

    vector<int> temp;

    while (!pq.empty())
    {
        temp.push_back(pq.top());
        pq.pop();
    }

    for (auto x : temp)
        cout << x << endl;

    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] != temp[i - 1])
        {
            if (temp[i] - temp[i - 1] == 1)
            {
                lenSoFar++;
            }
            else
            {
                maxL = max(maxL, lenSoFar);
                lenSoFar = 1;
            }
        }
    }
    maxL = max(maxL, lenSoFar);
    if (maxL == 0)
        return 1;
    return maxL;
}

int main()
{
    vector<int> arr{1, 2, 0, 1};
    cout << longestConsecutive(arr) << endl;
    return 0;
}