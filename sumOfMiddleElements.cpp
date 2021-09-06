#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
public:
    int findMidSum(int arr1[], int arr2[], int n)
    {
        int ptr1 = 0;
        int ptr2 = 0;

        int m1 = -1, m2 = -1;

        for (int count = 0; count < n; count++)
        {
            if (ptr1 == n)
            {
                m1 = m2;
                m2 = arr2[0];
                break;
            }
            if (ptr2 == n)
            {
                m1 = m2;
                m2 = arr1[0];
                break;
            }

            if (arr1[ptr1] < arr2[ptr2])
            {
                m1 = m2;
                m2 = arr1[ptr1];
                ptr1++;
            }
            else
            {
                m1 = m2;
                m2 = arr2[ptr2];
                ptr2++;
            }
        }

        return m1 + m2;
    }
};

int main()
{
    fast_cin();

    return 0;
}