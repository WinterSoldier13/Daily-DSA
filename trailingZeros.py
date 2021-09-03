class Solution:
    def trailingZeroes(self, n: int) -> int:
        count = 0
        i=5
        while (n/i>=1): 
            count += int(n/i) 
            i *= 5

        return int(count)
        