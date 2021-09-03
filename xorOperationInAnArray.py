class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        
        pr = 0
        for i in range(n):
            pr^=(start+2*i)
        return pr
        