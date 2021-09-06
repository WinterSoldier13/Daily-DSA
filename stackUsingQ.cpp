#include<bits/stdc++.h>
using namespace std;


class MyStack {
public:
    /** Initialize your data structure here. */

    queue<int> queue;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        vector<int> temp;
        if(queue.size() == 0)
        {
            queue.push(x);
            return;
        }
        while(!queue.empty())
        {
            temp.push_back(queue.front());
            queue.pop();
        }
        reverse(temp.begin() , temp.end());
        temp.push_back(x);
        reverse(temp.begin() , temp.end());
        for(int x: temp)
        {
            queue.push(x);
        }
        temp.clear();
        return;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(queue.size()==0)
        return -1;
        int val_ = queue.front();
        queue.pop();
        return val_;
        
    }
    
    /** Get the top element. */
    int top() {
        return queue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */