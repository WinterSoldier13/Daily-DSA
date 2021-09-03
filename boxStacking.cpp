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

bool customSort(vector<int> a1, vector<int> a2)
{
    int area1 = a1[0] * a1[1];
    int area2 = a2[0] * a2[1];

    return area1 < area2;
}

int maxHeight(int height[], int width[], int length[], int n)
{
    vector<vector<int>> boxes;

    for (int i = 0; i < n; i++)
    {
        boxes.push_back(vector<int>{height[i], width[i], length[i]});
        boxes.push_back(vector<int>{width[i], length[i], height[i]});
        boxes.push_back(vector<int>{height[i], length[i], width[i]});
    }
    sort(boxes.begin(), boxes.end(), customSort);

    vector<int> dp(boxes.size());
    for (int i = 0; i < boxes.size(); i++)
    {
        dp[i] = boxes[i][2];
    }

    int n = boxes.size();

    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if((boxes[j][0] < boxes[i][0] and boxes[j][1] < boxes[i][1]) or (boxes[j][0] < boxes[i][1] and boxes[j][1] < boxes[i][0]))
            {
                dp[i] = max(dp[i], dp[j] +  boxes[i][2]);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}
int main()
{
}