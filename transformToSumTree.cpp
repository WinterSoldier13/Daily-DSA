
int f(Node *node)
{
    if (!node)
        return 0;
    int d = node->data;
    int lsum = f(node->left);
    int rsum = f(node->right);
    node->data = lsum + rsum;
    return d + node->data;
}
void toSumTree(Node *node)
{
    f(node);
}
