#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

void myWay(vector<int> arr)
{
    int l = arr.size();
    set<int> hashset;

    for (auto x : arr)
    {
        if (hashset.count(x))
        {
            hashset.erase(x);
        }
        else
        {
            hashset.insert(x);
        }
    }
    for (auto it = hashset.begin(); it != hashset.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(2*n+2);
        for (int i = 0; i < 2*n+2; i++)
        {
            cin >> arr[i];
        }
        myWay(arr);
    }
}
