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
    int catchThieves(char arr[], int n, int k)
    {
        queue<int> arr1;
        queue<int> arr2;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 'T')
            {
                arr1.push(i);
            }
            else
                arr2.push(i);
        }
        int count = 0;


        while (arr1.size() != 0 and arr2.size() != 0)
        {
            int t = arr1.front();
            int p = arr2.front();

            if (abs(t - p) <= k)
            {
                arr1.pop();
                arr2.pop();
                count++;
            }
            else
            {
                if(arr1.front() < arr2.front())
                {
                    arr1.pop();
                }
                else
                {
                    arr2.pop();
                }
            }
        }
        cout<<count<<endl;
        return count;
    }
};

int main()
{
    fast_cin();

    char arr[] = {'T', 'T', 'P', 'P', 'T', 'P'};
    int n = sizeof(arr) / sizeof(arr[0]);


    Solution ob;
    ob.catchThieves(arr, n, 2);

    return 0;
}