#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

vector<int> multiply(vector<int> &A, vector<int> &B, int m, int n)
{
    vector<int> prod(m + n - 1, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            prod[i + j] += A[i] * B[j];
    }
    return prod;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int> A(m);
        vector<int> B(n);

        for (int i = 0; i < m; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
        }
        auto prod = multiply(A, B, m, n);
        for (auto x : prod)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}