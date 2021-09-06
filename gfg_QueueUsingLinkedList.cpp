
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};


struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};




/* The method push to push element into the queue*/
void MyQueue:: push(int x)
{
    QueueNode* newElement = new QueueNode(x);

    if(front == NULL)
    {
        front = rear = newElement;
        return;
    }
    rear->next = newElement;
    rear = rear->next;
    rear->next = NULL;
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
    if(front==NULL)
    {
        return -1;
    }
    int val = front->data;
    front = front->next;
    return val;
}
