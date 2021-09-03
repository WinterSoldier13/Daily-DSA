#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define characters hashmap

class Trie
{
public:
    struct Node
    {
        unordered_map<char, Node *> hashmap;
        bool isEnd;

        Node()
        {
            isEnd = false;
        }
    };

    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        //insert the first char
        Node *node = new Node();

        if (root->hashmap.find(word[0]) == root->hashmap.end())
            root->hashmap[word[0]] = node;
        else
        {
            node = root->hashmap[word[0]];
        }

        //insert the rest of the word
        for (int i = 1; i < word.size(); i++)
        {
            if (node->hashmap.find(word[i]) == node->hashmap.end())
            {
                Node *temp = new Node();

                node->hashmap[word[i]] = temp;
                node = temp;
            }
            else
            {
                node = node->hashmap[word[i]];
            }
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        if (root->characters.find(word[0]) == root->characters.end())
        {
            return false;
        }

        else
        {
            Node *node;
            node = root->hashmap[word[0]];

            int ptr = 1;
            cout << "HERE" << endl;

            while (node->characters.find(word[ptr]) != node->characters.end())
            {
                cout << "FOUND " << word[ptr] << endl;
                node = node->characters[word[ptr]];
                ptr++;
            }
            return node->isEnd and ptr == word.size();
        }
        return false;
    }

    vector<string> getAllStartingFrom(string query)
    {
        vector<string> out;
        vector<string> temp;

        if (root->hashmap.find(query[0]) == root->hashmap.end())
        {
            return out;
        }

        Node *node = root->hashmap[query[0]];
        int index = 1;

        while (index < query.size() and node->hashmap.find(query[index]) != node->hashmap.end())
        {
            // cout << "[COMMON] " << query[index] << endl;
            node = node->hashmap[query[index]];
            index++;
        }
        if (index != query.size())
        {
            return out;
        }

        recurse("", node, temp);

        // cout<<"HERE"<<endl;
        for (auto x : temp)
            out.push_back(query + x);

        sort(out.begin(), out.end());
        return out;
    }

    void recurse(string currentWord, Node *node, vector<string> &out)
    {
        // cout << "RECURSE BITCH" << endl;
        if (node->isEnd == true)
        {
            // cout << "END IS" << currentWord << endl;
            out.push_back(currentWord);
        }

        for (auto it = node->hashmap.begin(); it != node->hashmap.end(); it++)
        {
            recurse(currentWord + it->first, it->second, out);
        }
    }
};

void solve(vector<string> &arr, string query)
{
    Trie ob;
    for (auto x : arr)
        ob.insert(x);

    for (int i = 1; i <= query.size(); i++)
    {
        vector<string> possibles = ob.getAllStartingFrom(query.substr(0, i));
        if (possibles.size() == 0)
        {
            cout << 0 << endl;
            continue;
        }
        for (auto x : possibles)
            cout << x << " ";
        cout<<endl;

    }
    // ob.getAllStartingFrom(query);

    // cout<<ob.search("ayush")<<endl;
    // cout<<ob.search("aiyush")<<endl;
    // cout<<ob.search("aoyush")<<endl;
    // cout<<ob.search("aoyusah")<<endl;
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<string> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        string query;
        cin >> query;

        solve(arr, query);
    }
    return 1;
}