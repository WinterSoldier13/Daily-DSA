class Solution:
    def stringToInt(self,s):
        sum_ = 0
        l = len(s)
        count = l-1

        for i in range(l):
            ch = int(s[i])
            sum_+=(ch*pow(10,count))
            count-=1
        return sum_
    def multiply(self, num1: str, num2: str) -> str:
        n1 = self.stringToInt(num1)
        n2 = self.stringToInt(num2)

        return str(n1*n2)
        