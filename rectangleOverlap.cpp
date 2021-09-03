#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        // If they don't overlap then rect1 should be either left, up, right or down
        return !(rec1[2]<=rec2[0] or rec1[1]>=rec2[3] or rec1[0]>=rec2[2] or rec1[3]<=rec2[1]);
    }
};