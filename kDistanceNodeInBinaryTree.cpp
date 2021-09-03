#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define ll unsigned long long int

struct Node
{
    int data;
    struct Node *left, *right;
};

class solver
{
private:
public:
    unordered_map<int, Node *> parentOf;

    void initializeParent(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        parentOf[root->data] = NULL;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (curr->left)
            {
                parentOf[curr->left->data] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parentOf[curr->right->data] = curr;
                q.push(curr->right);
            }
        }
        return;
    }
    Node *t;
    void __init__()
    {
        t = NULL;
        parentOf.clear();
    }
    void inOrder(Node *root, int target)
    {
        if (root == NULL or t != NULL)
        {
            return;
        }
        inOrder(root->left, target);
        if (root->data == target)
        {
            t = root;
            return;
        }
        inOrder(root->right, target);
    }
    vector<int> bfs(Node *target, int k)
    {
        vector<int> out;

        if (k == 0)
        {
            out.push_back(target->data);
            return out;
        }

        queue<Node *> q;
        unordered_set<int> tracker;

        q.push(target);
        int currentDepth = 0;
        tracker.insert(target->data);

        while (!q.empty())
        {
            currentDepth++;
            int numberOfNodesHavingCurrentDepth = q.size();

            for (int i = 0; i < numberOfNodesHavingCurrentDepth; i++)
            {
                auto curr = q.front();
                q.pop();

                auto node1 = curr->left;
                auto node2 = curr->right;
                auto node3 = parentOf[curr->data];

                if (node1 != NULL and tracker.count(node1->data) == 0)
                {
                    tracker.insert(node1->data);
                    q.push(node1);
                    if (currentDepth == k)
                    {
                        out.push_back(node1->data);
                    }
                }
                if (node2 != NULL and tracker.count(node2->data) == 0)
                {
                    tracker.insert(node2->data);
                    q.push(node2);
                    if (currentDepth == k)
                    {
                        out.push_back(node2->data);
                    }
                }
                if (node3 != NULL and tracker.count(node3->data) == 0)
                {
                    tracker.insert(node3->data);
                    q.push(node3);
                    if (currentDepth == k)
                    {
                        out.push_back(node3->data);
                    }
                }
            }
            if (currentDepth > k)
            {
                break;
            }
        }
        reverse(out.begin(), out.end());
        out.pop_back();
        reverse(out.begin(), out.end());

        return out;
    }

    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        __init__();
        initializeParent(root);
        inOrder(root, target);

        return bfs(t, k);
    }
};

int main()
{
    return 1;
}