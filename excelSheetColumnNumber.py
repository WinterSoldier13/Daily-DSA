class Solution:
    def titleToNumber(self, inp: str) -> int:
        l = len(inp)


        hashmap={}
        chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'


        for index,ch in enumerate(chars):
            hashmap[ch] = index+1

        ptr = l-1
        sum_=0

        for i in inp:
            sum_ = sum_ + 26**ptr*hashmap[i]
            ptr-=1

        print(sum_)
        return sum_
        