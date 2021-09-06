/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    Node* temp = head;
    int l = 0;
    while(temp)
    {
        l++;
        temp = temp->next;
    }
    temp = head;
    Node* prev = head;
    if(x == 1)
    {
        return head->next;
    }
    
    for(int i=1;i<=l;i++)
    {
        
        if(i == x)
        {
            prev->next = temp->next;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}