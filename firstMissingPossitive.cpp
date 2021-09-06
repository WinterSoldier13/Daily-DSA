#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool allNeg(vector<int> &arr)
    {
        for (int x : arr)
            if (x > 0)
                return false;
        return true;
    }

    int swapNegatives(vector<int> &arr)
    {
        int p = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= 0)
            {
                swap(arr[i], arr[p++]);
            }
        }
        return --p;
    }

    int firstMissingPositive(vector<int> &arr)
    {
        if (arr.size() == 0)
        {
            return 1;
        }
        if (arr.size() == 1)
        {
            if (arr[0] == 1)
            {
                return 2;
            }
            return 1;
        }
        if (allNeg(arr))
        {
            return 1;
        }

        bool oneExist = false;
        for (auto x : arr)
            if (x == 1)
            {
                oneExist = true;
                break;
            }
        if (!oneExist)
        {
            return 1;
        }

        // Now it is asking for min so that will be in range 1 to size+1 THINK!!

        int l = arr.size();
        int negIndex = swapNegatives(arr);

        for (int i = 0; i <= negIndex; i++)
        {
            if (arr[i] == 0)
                arr[i] = 1;
            arr[i] = abs(arr[i]);
        }

        for (int i = negIndex + 1; i < l; i++)
        {
            if (abs(arr[i]) <= l and arr[abs(arr[i]) - 1] > 0)
            {
                int v = arr[abs(arr[i]) - 1];
                arr[abs(arr[i]) - 1] = -1 * v;
            }
        }

        for (int i = 0; i < l; i++)
        {
            if (arr[i] > 0)
            {
                return i + 1;
            }
        }
        return ++l;
    }
};