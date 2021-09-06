void inOrder(Node* root, int &count)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left,count);
    
    if(root->right==NULL and root->left ==NULL)
    {
        count++;
    }
    
    inOrder(root->right, count);
}
int countLeaves(Node* root)
{
  int count = 0;
  inOrder(root, count);
  return count;
}