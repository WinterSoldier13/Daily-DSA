import math

# http://codeforces.com/blog/entry/53763
class Solution:
    def consecutiveNumbersSum(self, N):
        count = 1
        
        for i in range(2, math.ceil(math.sqrt(2 * N))):
            x = N / i - i / 2 + 0.5
            if x == int(x): count += 1
        return count