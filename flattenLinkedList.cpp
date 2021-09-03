
Node *flatten(Node *root)
{
    vector<int> arr;
    while(root!=NULL)
    {
       
        arr.push_back(root->data);
        Node* temp =root->bottom;
        while(temp!=NULL)
        {
            arr.push_back(temp->data);
            temp = temp->bottom;
        }
        root=root->next;
    }

    sort(arr.begin(), arr.end());

    Node* head = new Node(-1);
    Node* help = head;

    for(int x: arr)
    {
        Node* temp = new Node(x);
        help->bottom = temp;
        help = temp;
    }
    head = head->bottom;
    return head;
}