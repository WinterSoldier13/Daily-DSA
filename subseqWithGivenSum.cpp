#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

pair<int, int> contSum(vector<int> &arr, int s)
{
    int ptr1 = 0;
    int ptr2 = 0;
    int l = arr.size();
    pair<int, int> out;
    int currentSum = 0;

    while (ptr2 < l)
    {
        while (currentSum > s and ptr1 < ptr2)
        {

            currentSum -= arr[ptr1];
            ptr1++;
        }
        if (currentSum == s)
        {
            out = make_pair(ptr1 + 1, ptr2);
            break;
        }

        currentSum += arr[ptr2];

        ptr2++;
    }
    return out;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, s;
        scanf("%d %d", &n, &s);

        vector<int> arr(n);
        for (auto i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        auto ans = contSum(arr, s);

        if (ans.first == 0 and ans.second == 0)
        {
            cout << -1;
            continue;
        }

        printf("%d %d\n", ans.first, ans.second);
    }
}