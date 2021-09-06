#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

class Solution
{
private:
    string sumString(string num1, string num2)
    {
        if (num2.size() > num1.size())
        {
            return sumString(num2, num1);
        }
        int carry = 0;

        string out = "";

        int l1 = num1.size();
        int l2 = num2.size();
        int ptr1 = l1-1;
        for (int i = l2 - 1; i >= 0; i--)
        {
            int n1 = num1[ptr1--] - '0';
            int n2 = num2[i] - '0';

            int sum = n1 + n2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            out += (digit + '0');
        }
        for (int i = l1 - l2 - 1; i >= 0; i--)
        {
            int n1 = num1[i] - '0';

            int sum = n1 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            out += (digit + '0');
        }
        

        if (carry)
        {
            out += (carry + '0');
        }

        reverse(out.begin(), out.end());

        ptr1 = 0;
        while(out[ptr1] == '0')
        {
            ptr1++;
        }

        out = out.substr(ptr1);

        return out;
    }

public:
    string solve(int arr[], int n)
    {

        sort(arr, arr + n);

        string num1 = "";
        string num2 = "";

        for (int i = 0; i < n; i += 2)
        {
            if (arr[i] == '0' and num1.size() != 0)
                num1 += (arr[i] + '0');
            else if (arr[i] != '0')
            {
                num1 += (arr[i] + '0');
            }
        }
        for (int i = 1; i < n; i += 2)
        {
            if (arr[i] == '0' and num2.size() != 0)
                num2 += (arr[i] + '0');
            else if (arr[i] != '0')
            {
                num2 += (arr[i] + '0');
            }
        }
        return sumString(num1, num2);
    }
};

int main()
{
    int arr[] = {6, 8, 4, 5, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution ob;
    cout << ob.solve(arr, n) << endl;
    return 0;
}