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

struct huffmanTreeNode
{
    char ch;
    int freq;

    huffmanTreeNode *left;
    huffmanTreeNode *right;

    huffmanTreeNode(char c, int f, huffmanTreeNode *l, huffmanTreeNode *r)
    {
        ch = c;
        freq = f;
        left = l;
        right = r;
    }
};

class Compare
{
public:
    bool operator()(huffmanTreeNode *a, huffmanTreeNode *b)
    {
        return a->freq > b->freq;
    }
};

class Solution
{
private:
    vector<string> out;
    huffmanTreeNode *generateHuffmanTree(priority_queue<huffmanTreeNode *, vector<huffmanTreeNode *>, Compare> &minHeap)
    {
        while (minHeap.size() != 1)
        {
            auto leftChild = minHeap.top();
            minHeap.pop();

            auto rightChild = minHeap.top();
            minHeap.pop();

            huffmanTreeNode *node = new huffmanTreeNode(' ', leftChild->freq + rightChild->freq, leftChild, rightChild);

            minHeap.push(node);
        }
        return minHeap.top();
    }

    void preOrderPrint(huffmanTreeNode *root, string path)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL and root->right == NULL)
        {
            out.push_back(path);
            return;
        }

        if (root->left)
        {
            preOrderPrint(root->left, path + "0");
        }
        if (root->right)
        {
            preOrderPrint(root->right, path + "1");
        }
    }

public:
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        out.clear();
        priority_queue<huffmanTreeNode *, vector<huffmanTreeNode *>, Compare> minHeap;

        for (int i = 0; i < N; i++)
        {
            huffmanTreeNode *node = new huffmanTreeNode(S[i], f[i], NULL, NULL);
            minHeap.push(node);
        }

        auto huffmanTreeRoot = generateHuffmanTree(minHeap);
        vector<int> arr(26);
        int top = 0;

        preOrderPrint(huffmanTreeRoot, "");

        return out;
    }
    ~Solution()
    {
        out.clear();
    }
};

int main()
{
    fast_cin();

    string s = "abcdef";
    vector<int> f{5, 9, 12, 13, 16, 45};

    Solution ob;
    ob.huffmanCodes(s, f, s.size());

    return 0;
}