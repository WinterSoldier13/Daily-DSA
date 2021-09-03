vector<vector<Node*>> mothership;
void recurseBitch(Node* root, vector<Node*> &path)
{
    if(root == NULL)
    {
        return;
    }
    path.push_back(root);
    if(root->left == NULL and root->right == NULL)
    {
        mothership.push_back(path);
        return;
    }
    if(root->left != NULL)
    {
        recurseBitch(root->left, path);
        path.pop_back();
    }
    if(root->right != NULL)
    {
        recurseBitch(root->right, path);
        path.pop_back();
    }
}
int printKDistantfromLeaf(Node* root, int k)
{
	mothership.clear();
    vector<Node*> path;

    recurseBitch(root, path);

    unordered_set<Node*> hashset;
    for(auto x : mothership)
    {
        if(x.size() >k)
        {
            hashset.insert(x[x.size()-k-1]);
        }
    }
    return hashset.size();
}