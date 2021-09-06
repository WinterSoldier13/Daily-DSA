#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long int

void recurse(vector<vector<int>> &graph, int node, unordered_set<int> &track, stack<int> &stack)
{

    track.insert(node);

    for (auto x : graph[node])
    {
        if (track.find(x) == track.end())
            recurse(graph, x, track, stack);
    }
    stack.push(node);
}

string dfs(vector<vector<int>> &graph, int k, unordered_map<int, char> &indexing)
{
    unordered_set<int> track;
    stack<int> stack;

    for (int i = 0; i < k; i++)
    {
        if (track.find(i) == track.end())
            recurse(graph, i, track, stack);
    }

    string s="";
    while(!stack.empty())
    {
        s+=indexing[stack.top()];
        stack.pop();
    }
    return  s;


}

string alienDict(vector<string> arr, int k)
{
    int l = arr.size();
    unordered_set<char> hashset;
    unordered_map<int, char> indexing;
    unordered_map<char, int> charIndexing;
    int count = 0;
    for (auto x : arr)
    {
        for (auto c : x)
        {
            if (hashset.count(c))
            {
                continue;
            }
            else
            {
                indexing[count] = c;
                charIndexing[c] = count;
                count++;
                hashset.insert(c);

                if (count == k)
                {
                    break;
                }
            }
        }
    }

    // for(auto it = indexing.begin(); it!=indexing.end();it++)
    // {
    //     cout<<it->first<<" "<<it->second<<endl;
    // }


    vector<int> t;
    vector<vector<int>> graph(k, t);

    for (int i = 0; i < l - 1; i++)
    {
        string word1 = arr[i];
        string word2 = arr[i + 1];

        

        int l1 = word1.size();
        int l2 = word2.size();

        for (int j = 0; j < min(l1, l2); j++)
        {
            if (word1[j] != word2[j])
            {
                int char2int1 = charIndexing[word1[j]];
                int char2int2 = charIndexing[word2[j]];
                // cout<< char2int1<< " "<<char2int2<<endl;

                graph[char2int1].push_back(char2int2);
                break;
            }
        }
    }

    // cout<<endl<<"GRAPH"<<endl;

    // count = 0;
    // for(auto x :graph)
    // {
    //     cout<<count++<<" || ";
    //     for(auto c: x)
    //     {
    //         cout<<c<<" ";
    //     }
    //     cout<<endl;
    // }

    return dfs(graph, k ,indexing);
    
}

int main()
{
    vector<string> arr{ "caa", "aaa", "aab"};
    int k = 3;

    cout<<alienDict(arr, k)<<endl;

}