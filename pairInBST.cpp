int res;
unordered_set<int> hashset;
int T;

void inOrder(Node* root)
{
    
    if(root == NULL or res == 1)
    {
        return;
    }
    inOrder(root->left);
    int required = T-root->data;
    if(hashset.count(required))
    {
        res = 1;
        return;
    }
    else
    hashset.insert(root->data);
    inOrder(root->right);
}
int isPairPresent(struct Node *root, int target)
{
    res = 0;
    T = target;
    hashset.clear();
    
    inOrder(root);
    return res;
}