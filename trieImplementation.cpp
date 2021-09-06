#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode *> characters;
    bool isEnd = false;
};

class Trie
{
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        if (root->characters.find(word[0]) == root->characters.end())
        {
            TrieNode *node = new TrieNode();

            root->characters[word[0]] = node;
            cout << "INSERTING " << word[0] << endl;

            int l = word.size();

            for (int i = 1; i < l; i++)
            {
                char ch = word[i];
                TrieNode *temp = new TrieNode();
                cout << "INSERTING " << word[i] << endl;

                node->characters[ch] = temp;
                node = temp;
            }
            node->isEnd = true;
            unordered_map<char, TrieNode *> temp;
            node->characters = temp;
        }

        else
        {
            int ptr = 0;

            TrieNode *node = root->characters[word[ptr]];
            ptr = 1;

            while (node->characters.find(word[ptr]) != node->characters.end())
            {
                node = node->characters[word[ptr]];
                ptr++;
            }

            int l = word.size();

            if (ptr == l)
            {
                node->isEnd = true;
            }
            else
            {
                for (int i = ptr; i < l; i++)
                {
                    TrieNode *temp = new TrieNode();
                    node->characters[word[i]] = temp;
                    node = temp;
                }
                node->isEnd = 1;
            }
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        if (root->characters.find(word[0]) == root->characters.end())
        {
            return false;
        }

        else
        {
            TrieNode *node = root->characters[word[0]];

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

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word)
    {
        if (root->characters.find(word[0]) == root->characters.end())
        {
            return false;
        }

        else
        {
            TrieNode *node = root->characters[word[0]];

            int ptr = 1;

            while (node->characters.find(word[ptr]) != node->characters.end())
            {
                node = node->characters[word[ptr]];
                ptr++;
            }
            return ptr == word.size();
        }
        return false;
    }
};

int main()
{
    Trie ob;

    ob.insert("Ayush");
    ob.insert("Singh");
    ob.insert("Ayushi");

    cout << " " << ob.search("Ayush") << endl;
    cout << " " << ob.search("Singh") << endl;
    cout << " " << ob.search("Singha") << endl;
    cout << " " << ob.search("Ayushi") << endl;

    return 0;
}