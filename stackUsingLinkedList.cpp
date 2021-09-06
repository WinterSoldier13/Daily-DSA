
/*
The structure of the node of the stack is
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

// And this is structure of MyStack
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
void MyStack ::push(int x) {
    // Your Code
    StackNode* node = new StackNode(x);
    node->next = top;
    top = node;
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop() {
    // Your Code
    if(top == NULL)
    {
        return -1;
    }
    int val = top->data;
    top = top->next;
    return val;
}