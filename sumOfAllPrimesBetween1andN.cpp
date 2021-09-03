#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

int isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<int> arr{2, 3};

    while (t--)
    {
        int n;
        cin >> n;

        if (arr[arr.size() - 1] >= n)
        {
            lli sum_ = 0;
            for (int i = 0; arr[i] <= n; i++)
            {
                sum_ += arr[i];
            }
            cout << sum_ << endl;
            continue;
        }
        else
        {
            lli sum_ = 0;
            for (auto x : arr)
            {
                sum_ += x;
            }
            int lastPrime = arr[arr.size() - 1];
            for (int i = lastPrime + 1; i <= n; i++)
            {
                if (isPrime(i))
                {
                    arr.push_back(i);
                    sum_ += i;
                }
            }

            cout << sum_ << endl;
        }
    }
}