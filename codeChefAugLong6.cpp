#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

vector<int> out;

void __init__(int n)
{
    vector<int> temp(n, 0);
    out = temp;
}


int findMaxFreq(vector<int> &arr)
{
    unordered_map<int, int> hashmap;
    for (int x : arr)
    {
        hashmap[x]++;
    }
    int maxFreq = 0;
    int maxNumber = INT16_MAX;
    for (auto it = hashmap.begin(); it != hashmap.end(); it++)
    {
        int freq = it->second;
        int number = it->first;

        if (freq >= maxFreq)
        {
            maxNumber = min(maxNumber, number);
            maxFreq = freq;
        }
    }
    if (maxNumber == INT16_MAX)
    {
        return -1;
    }
    return maxNumber;
}

void printVec(vector<int> &arr)
{
    for (auto c : arr)
    {
        cout << c << " ";
    }
}

void printCombinations(vector<int> arr, int i, vector<int> support)
{
    if (i == arr.size() - 1)
    {
        // printVec(support);
        int maxE;
        maxE = findMaxFreq(support);
        if (maxE > 0)
        {
            out[maxE - 1]++;
        }

        support.push_back(arr[i]);

        // printVec(support);
        maxE = findMaxFreq(support);
        if (maxE > 0)
        {
            out[maxE - 1]++;
        }

        return;
    }
    vector<int> temp = support;
    temp.push_back(arr[i]);

    printCombinations(arr, i + 1, support);

    printCombinations(arr, i + 1, temp);
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // vector<int> arr{1, 2, 2};
        vector<int> support;
        int i = 0;

        vector<int> temp(n, 0);
        out = temp;
        printCombinations(arr, i, support);

        

        for(int i=0;i<n;i++)
        {
            printf("%d ", out[i]);
        }
        printf("\n");
    }
}
