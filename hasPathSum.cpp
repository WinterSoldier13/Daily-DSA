bool hasPathSum(Node *root, int sum)
{
   if(root==NULL || sum==0)return 0;
   if(!root->left && !root->right) return (sum-root->data == 0);
   
   return( hasPathSum(root->left,sum-root->data)|| hasPathSum(root->right,sum-root->data) );
   
}
