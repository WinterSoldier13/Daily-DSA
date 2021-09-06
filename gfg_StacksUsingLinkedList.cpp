
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyStack {
private:
StackNode *top;
public :
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};

/* The method push to push element
   into the stack */
void MyStack ::push(int x) 
{
    StackNode* node = new StackNode(x);
    if(top == NULL)
    {
        top = node;
        return;
    }
    node->next = top;
    top = node;
    
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop() 
{
    if(top==NULL)
    {
        return -1;
    }
    int val = top->data;
    top = top->next;
    return val;

    
}
