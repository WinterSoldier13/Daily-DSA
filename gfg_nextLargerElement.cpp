#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        vector<long long int> arr(n, 0);
        for (long long int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        stack<long long int> stack;
        reverse(arr.begin(), arr.end());

        vector<long long int> out;
        out.push_back(-1);
        stack.push(arr[0]);

        for (long long int i = 1; i < n; i++)
        {
            if (arr[i] < stack.top())
            {
                out.push_back(stack.top());
                stack.push(arr[i]);
                continue;
            }
            else
            {
                while (!stack.empty() and stack.top() < arr[i])
                    stack.pop();
                if (stack.empty())
                {
                    out.push_back(-1);
                    stack.push(arr[i]);
                }
                else
                {
                    out.push_back(stack.top());
                    stack.push(arr[i]);
                }
            }
        }
        reverse(out.begin(), out.end());
        for (auto c : out)
            cout << c << " ";
        cout << endl;
    }
}