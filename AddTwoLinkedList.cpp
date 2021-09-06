    Node* addTwoNumbers(Node* h1, Node* h2) 
    {
        Node* head1 = h1;
        Node* head2 = h2;
        
        int l1=0, l2=0;
        
        while(h1!=NULL)
        {
            l1++;
            h1 = h1->next;
        }
        while(h2!=NULL)
        {
            l2++;
            h2 = h2->next;
        }
        h1 = head1;
        h2 = head2;
        
        int carry  =0;
        
        if(l1>l2)
        {
            while(h2->next != NULL)
            {
                h2 = h2->next;
            }
           for(int i=0;i<l1-l2;i++)

            {
                Node* node = new Node(0);
                h2->next = node;
                h2 = node;
            }
            h2->next = NULL;
        }
        else
        {
            while(h1->next != NULL)
            {
                h1 = h1->next;
            }
            for(int i=0;i<l2-l1;i++)

            {
                Node* node = new Node(0);
                h1->next = node;
                h1 = node;
            }
            h1->next = NULL; 
        }
        
        
        int l = max(l1, l2);
        
        Node* head = new Node(0);
        Node* temp = head;
        int sum;
        
        for(int i =0;i<l;i++)
        {
            if(i == 0)
            {
                sum = head1->data + head2->data + carry;
                carry = sum/10;
                int append = sum%10;
                head->data = append;
                temp = head;
            }
            else
            {
                sum = head1->data + head2->data + carry;
                carry = sum/10;
                int append = sum%10;
                Node* node = new Node(append);
                temp->next = node;
                temp = node;

            }
            head1 = head1->next;
            head2 = head2->next;
            
        }
        if(carry != 0)
        {
            Node* node = new Node(carry);
            temp->next = node;
            temp = node;

        }
        
        temp->next = NULL;
        
        return head;
    }