#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int
#define tiii tuple<int, int, int, int>

int main()
{
    int t;
    scanf("%d", &t);
    int n, k;

    while (t--)
    {
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int count = 0;
        bool flag = false;
        int ptr1 = 0;

        while (ptr1<n)
        {
            int sum_ = 0;
            if (arr[ptr1] > k)
            {
                flag = true;
                break;
            }
            while (ptr1<n and sum_ + arr[ptr1] <= k)
            {

                sum_ += arr[ptr1];
                arr[ptr1] = 0;
                ptr1++;
            }
            count++;
        }

        if (flag)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << count << endl;
        }
    }
}
