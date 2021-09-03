
unordered_set<int> hashset;
vector<int> out;
void recurse(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    recurse(root->left);
    
    if(root->left == NULL and root->right!=NULL)
    {
        out.push_back(root->right->data);
    }
    if(root->left != NULL and root->right ==NULL)
    {
        out.push_back(root->left->data);
    }
    
    recurse(root->right);
    
    
}

vector<int> noSibling(Node* node)
{
    hashset.clear();
    out.clear();
    
    recurse(node);
    if(out.size() == 0)
    {
        out.push_back(-1);
    }
    sort(out.begin(), out.end());
    return out;
    
}