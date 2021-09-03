bool recurse(Node* ptr1, Node* ptr2)
{
    if(ptr1 == NULL and ptr2 == NULL)
    {
        return true;
    }
    if(ptr1 == NULL or ptr2 == NULL)
    {
        return false;
    }
    
    if(recurse(ptr1->left, ptr2->right) and recurse(ptr1->right, ptr2->left))
    {
        return true;
    }
    return false;
    
}
bool IsFoldable(Node* root)
{
    return recurse(root, root);
}