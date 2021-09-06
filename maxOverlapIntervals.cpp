#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

void solve(vector<pii> arr)
{
    sort(arr.begin(), arr.end());

    stack<pii> stack;
    int maxTime = -1;
    int currentLen = -1;
    for(int i=0;i<arr.size(); i++)
    {
        auto curr = arr[i];
        if(stack.empty())
        {
            stack.push(curr);
            currentLen = 1;
            maxTime = curr.first;
            continue;
        }
        if(curr.first > stack.top().second)
        {
            stack.pop();
            
            stack.push(curr);
            maxTime = curr.first;
            continue;
        }
        else if(curr.first <= stack.top().second)
        {
            pii temp;
            temp.first = stack.top().first;

            temp.second = max(curr.second, stack.top().second);
            currentLen ++;
            maxTime = curr.first;
        }
    }

    cout<<currentLen<<" "<<maxTime<<endl;
}

int main()
{
    fast_cin();
    cin.tie(NULL);

    int t;
    cin>>t;
    
    while (t--)
    {
        int n;
        cin>>n;

        vector<pii> arr(n);

        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            arr[i].first = temp;
        }

        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            arr[i].second = temp;
        }

        solve(arr);
    }
    
    return 0;
}