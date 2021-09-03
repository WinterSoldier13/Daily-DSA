#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int
#define pii pair<int, int>

struct Node
{
    int key;
    Node *left;
    Node *right;
};

int findMirrorRec(int target, struct Node *left,
                  struct Node *right)
{

    if((!left&&!right)||(!left&&right)||(left&&!right))
    {
        return -1;
    }

    if (left->key == target)
    {
        return right->key;
    }
    if (right->key == target)
    {
        return left->key;
    }

    else
    {
        int l = findMirrorRec(target, left->left, right->right);
        int r = findMirrorRec(target, left->right, right->left);

        if (l == -1 and r == -1)
        {
            return -1;
        }
        return l == -1 ? r : l;
    }
    return 0;
}
