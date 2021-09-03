#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cutoff = arr[k - 1];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 and arr[i] >= cutoff)
        {
            count++;
            // cout<<i<<endl;
        }
    }
    cout << count << endl;
}
