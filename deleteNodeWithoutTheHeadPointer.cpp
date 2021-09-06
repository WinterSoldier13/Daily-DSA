void deleteNode(Node *node)
{
   if(node==NULL)
   return;
   
   Node* prev;
    while(node->next!=NULL)
    {
        node->data = node->next->data;
        prev = node;
        node = node->next;
    }
    prev->next = NULL;
}

