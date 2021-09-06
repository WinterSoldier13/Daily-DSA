int recurse(Node* root, int K, vector<int> &out)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL and root->right == NULL)
    {
        return 1;
    }
    int lCount = recurse(root->left, K, out);
    int rCount = recurse(root->right, K, out);

    int currentCount = lCount + rCount;
    if(currentCount == K)
    {
        out.push_back(root->data);
    }
    return currentCount;
}

vector<int> btWithKleaves(Node *ptr, int k)
{ 
    vector<int> out;
    recurse(ptr, k, out);
    if(out.size() == 0)
    out.push_back(-1);
    return out;
}