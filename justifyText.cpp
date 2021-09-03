#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define getT() \
    int t;     \
    cin >> t;  \
    while (t--)
#define lli long long int
#define pii pair<int, int>
#define endl '\n'
#define printArr(arr)     \
    for (auto x : arr)    \
        cout << x << " "; \
    cout << endl;
#define printHashmap(hashmap)                                  \
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) \
    {                                                          \
        cout << it->first << " " << it->second << endl;        \
    }
#define print2DArray(arr)     \
    for (auto x : arr)        \
    {                         \
        for (auto c : x)      \
            cout << c << " "; \
        cout << endl;         \
    }

// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________
// _______________________________________________________________________________________________________________________________________________________________________________

vector<string> solve(vector<string>& arr , int k) 
{
    vector<vector<string>> out;
    vector<int> spaceCountOnEachLine;
    int characterCount = 0;
    int l = arr.size();

    int count = 0;
    vector<string> temp;
    for(int i=0;i<arr.size();i++)
    {
        if(count+arr[i].size() <= k)
        {
            count+=arr[i].size();
            characterCount+=arr[i].size();
            count++;
            temp.push_back(arr[i]);
        }
        else
        {
            out.push_back(temp);
            spaceCountOnEachLine.push_back(k-characterCount);
            temp.clear();
            count = 0;
            temp.push_back(arr[i]);
            count+=arr[i].size();
            characterCount=arr[i].size();
            count++;
        }
    } 
    out.push_back(temp);
    spaceCountOnEachLine.push_back(k-characterCount);

    vector<string> ans;
    l = out.size();
 
    for(int i=0;i<l;i++)
    {
        int spaceLimit = spaceCountOnEachLine[i];
        int spaceCount = out[i].size() -1;

        if(spaceCount==0)
        {
            ans.push_back(out[i][0]);
            while(spaceLimit--)
                ans.back().append(" ");
            continue;
        }

        int space = spaceLimit/spaceCount;
        int extraSpaceCount = spaceLimit%spaceCount;
      

        int l2 = out[i].size();
        string t = "";
        int spaceAdded = 0;
        for(int j=0;j<l2;j++)
        {
            string word = out[i][j];
            t.append(word);
            if(spaceAdded == spaceLimit) break;
            for(int k=0;k<space;k++)
            {
                t.append(" ");
                spaceAdded++;
            }
            if(extraSpaceCount>0)
            {
                t.append(" ");
                extraSpaceCount--;
                spaceAdded++;
            }
        }
        ans.push_back(t);
    }

    return ans;
}


int main()
{
    fast_cin();

    vector<string> arr{"the", "battle", "for", "soup", "versus", "salad", "is", "raging", "in", "the", "other", "room"};
    int k = 50;
    auto ans = solve(arr, k);

    for(auto x: ans)
        cout<<x<<endl;

    return 0;
}
