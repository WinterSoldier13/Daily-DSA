Node* segregate(Node *head) 
{
    Node* ptr = head;
    int countZero=0;
    int countOne=0;
    int countTwo=0;
    while(head!=NULL)
    {
        if(head->data == 0)
        {
            countZero++;
        }
        if(head->data == 1)
        {
            countOne++;
        }
        if(head->data == 2)
        {
            countTwo++;
        }
        head = head->next;
    }    

    head = ptr;
    while(countZero--)
    {
        head->data = 0;
        head= head->next;
    }
    while(countOne--)
    {
        head->data = 0;
        head= head->next;
    }
    while(countTwo--)
    {
        head->data = 0;
        head= head->next;
    }


    return ptr;
}
