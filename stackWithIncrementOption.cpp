class CustomStack {
public:
    vector<int> stk;
    int top, max;
    CustomStack(int maxSize) {
        top = 0;
        max = maxSize;
    }
    
    void push(int x) {
        if (top == max)
            return;
        stk.push_back(x);
        ++top;
    }
    
    int pop() {
        if (top == 0)
            return -1;
        int popped = stk.back();
        stk.pop_back();
        --top;
        return popped;
    }
    
    void increment(int k, int val) {
        for (int i=0; i<min(k, top); ++i)
            stk[i] += val;
    }
};
