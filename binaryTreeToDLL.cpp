
/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL


vector<int> arr;

void inOrder(Node* root)
{
    if(root==NULL)
    {
        return ;
    }
    inOrder(root->left);
    arr.push_back(root->data);
    inOrder(root->right);
}

Node * bToDLL(Node *root)
{
    // your code here
    inOrder(root);
    Node* head = new Node();
    head->data = arr[0];
    Node* temp1 = head;
    Node* temp2 = head;
    head->left = NULL;

    int l = arr.size();

    for(int i=1;i<l;i++)
    {
        Node* node = new Node();
        node->data = arr[i];
        temp1->right = node;
        temp1 = node;
        temp1->left = temp2;
        temp2 = temp2->right;
    }
    temp2->right = NULL;
    arr.clear();

    return head;

}