class Solution
{
public:
    // DO watch
    // https://www.youtube.com/watch?v=r0-zx5ejdq0

    int longestValidParentheses(string s)
    {
        stack<int> stack;
        stack.push(-1);

        int l = s.size();
        int maxLen = 0;

        for (int i = 0; i < l; i++)
        {
            char ch = s[i];

            if (ch == '(')
            {
                stack.push(i);
            }
            else
            {
                int stackTop = stack.top();
                if (stackTop != -1)
                {
                    char atTop = s[stackTop];

                    if (atTop == '(')
                    {
                        stack.pop();
                        maxLen = max(maxLen, i - stack.top());
                    }
                    else
                    {
                        stack.push(i);
                    }
                }
                else
                    stack.push(i);
            }
        }
        cout << maxLen << endl;
        return maxLen;
    }
};