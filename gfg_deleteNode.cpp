
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
#define val data
void deleteNode(Node *node)
{
    if(!node)
    {
        return;
    }
    Node* temp;
    while(node->next!=NULL)
    {
        node->val = node->next->val;
        temp = node;
        node = node->next;
    }
    temp->next = NULL;
}
