int ans;
int k;
void inOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left);
    
    ans = min(ans, abs(root->data - k));
    
    inOrder(root->right);
    
}
int minDiff(Node *root, int K)
{
    ans = INT_MAX;
    k =K;
    
    inOrder(root);
    return ans;
}
