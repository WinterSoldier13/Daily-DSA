class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        def operation(op1,op2,op):
            if op == "+":
                return op1 + op2
            if op == "-":
                return op1 - op2
            if op == "*":
                return op1 * op2
            if op == "/":
                return int(op1/op2)
        
        stack = []
        for char in tokens:
            if char in ["+", "-", "*", "/"]:
                op2 = stack.pop()
                op1 = stack.pop()
                res = operation(op1,op2,char)
                stack.append(int(res))
            else:
                stack.append(int(char))
        return stack.pop()