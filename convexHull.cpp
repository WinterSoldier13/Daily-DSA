#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int


// todo need to fix

class Solution
{
public:
    int X;
    int Y;

    bool operator()(pair<int,int> point1, pair<int,int> point2)
    {
            int x1 = point1.first;
            int y1 = point1.second;

            int x2 = point2.first;
            int y2 = point2.second;

            int value = ((y2 - Y) * (x1 - X)) - ((y1 - Y) * (x2 - X));

            if (value <= 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
            return 0;
    }

    int getTheTurn(pair<int,int> A, pair<int,int> B, pair<int,int> C)
    {
        int x1 = A.first;
        int y1 = A.second;
        
        int x2 = B.first;
        int y2 = B.second;

        int x3 = C.first;
        int y3 = C.second;

        int value = ((y3-y1)*(x2-x1) - ((y2-y1)*(x3-x1)));
        // if current turn is straight then left return 1
        return value>=0;
    }
    vector<vector<int>> FindConvexHull(vector<vector<int>> points_list)
    {
        // find the point with minimum y coordinate
        vector<int> x1{0, INT_MAX};

        for (auto x : points_list)
        {
            if (x[1] < x1[1])
            {
                x1 = x;
            }
        }
        X = x1[0];
        Y = x1[1];

        // sort all the points in terms of angle from x1
        vector<pair<int,int>> arr;
        for(auto x: points_list)
        {
            if(x[0] == X and x[1] == Y)
            {
                continue;
            }
            arr.push_back({x[0], x[1]});
        }
        cout<<X<<" "<<Y<<endl;

        sort(arr.begin(), arr.end() , operator() );

        for(auto x: arr)
        {
            cout<<x.first<<","<<x.second<<" ";
        }
        cout<<endl;

        // now check 
        int l = arr.size();
        stack<pair<int,int>> stack;

        stack.push({X,Y});
        stack.push(arr[0]);

        for(int i=2;i<l;i++)
        {
            auto C = arr[i];
            auto B = stack.top();
            stack.pop();
            auto A = stack.top();
            stack.pop();

            int turn = getTheTurn(A, B, C);

            if(turn == 1)
            {
                stack.push(A);
                stack.push(B);
                stack.push(C);
            }
            else
            {
                stack.push(A);
                stack.push(C);
            }
        }
        vector<vector<int>> out;

        while (!stack.empty())
        {
            out.push_back(vector<int> {stack.top().first, stack.top().second});
            stack.pop();
        }
        sort(out.begin(), out.end());
        if(out.size() == 0)
        {
            out.push_back(vector<int> {-1});
            return out;
        }
        return out;
    }
};

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> arr{{9,1}, {-10, -6}, {2,2}, {8,5}, {10, -4}, {-10,-1}};

    Solution ob;
    auto out = ob.FindConvexHull(arr);

    for(auto x: out)
    {
        cout<<x[0]<<" "<<x[1]<<endl;
    }
    return 1;
}
