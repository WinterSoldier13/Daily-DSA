bool isMirror(Node* r1, Node* r2)
{
    if(r1 == NULL and r2 == NULL)
    {
        return 1;
    }
    if(r1==NULL or r2==NULL)
    {
        return 0;
    }
    if(r1->data != r2->data)
    {
        return 0;
    }
    
    return isMirror(r1->left, r2->right) and isMirror(r1->right, r2->left);
}
bool isSymmetric(struct Node* root)
{
return isMirror(root, root);
}