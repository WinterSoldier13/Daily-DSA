#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false)
#define lli unsigned long long int

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
int max_;
 
int recurse(Node* root)
{
    if(root == NULL)
    {
        return INT32_MAX;
    }
    if(root -> left == NULL and root->right == NULL)
    {
        return root->data;
    }

    int valL = recurse(root->left);
    int valR = recurse(root->right);

    int diff =max(root->data - valL, root->data - valR);

    max_ = max(max_, diff);

    return min(min(valL, valR), root->data);
}
int maxDiff(Node* root)
{
    max_ = INT_MIN;
    recurse(root);

    return max_;
}

int main()
{
    fast_cin();
    cin.tie(NULL);
    cout.tie(NULL);


    return 1;
}