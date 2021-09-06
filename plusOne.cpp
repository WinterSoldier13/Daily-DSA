#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &arr)
{

    vector<int> out;

    reverse(arr.begin(), arr.end());

    int sum = arr[0] + 1;
    int carry = sum / 10;
    int digit = sum % 10;

    out.push_back(digit);

    int l = arr.size();

    for (int i = 1; i < l; i++)
    {
        sum = carry + arr[i];
        carry = sum / 10;
        digit = sum % 10;
        out.push_back(digit);
    }
    if (carry != 0)
    {
        out.push_back(carry);
    }
    reverse(out.begin(), out.end());
    return out;
}