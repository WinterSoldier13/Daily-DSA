int t;
vector<int> ans;
void recurse(Node* root, vector<int> &path)
{
    if(root == NULL)
    {
        return;
    }
    if(root->data == t)
    {
        ans = path;
        return;
    }
    path.push_back(root->data);
    
    if(root->left)
    {
        recurse(root->left, path);
        path.pop_back();
    }
    if(root->right)
    {
        recurse(root->right, path);
        path.pop_back();
    }
}
vector<int> Ancestors(struct Node *root, int target)
{
    vector<int> out;
    t = target;
    ans.clear();
    recurse(root, out);
    reverse(ans.begin(), ans.end());
    return ans;
    
    
}