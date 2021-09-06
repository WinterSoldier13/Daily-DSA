class Solution:
    def titleToNumber(self, inp: str):
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

    def numberToTile(self, num: int):
        hashmap = {}
        abc = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        for index,char in enumerate(abc):
            hashmap[index+1] = char
        out = ''
        while(int(num)>0):
            n = num%26
            # print(n)
            if(n == 0):
                out+='Z'
                num = num/26 -1
            else:
                out+=hashmap[int(n)]
                num/=26
        out = out[::-1]
        print(out)  





ob = Solution()
for _ in range(int(input())):
    ob.numberToTile(int(input()))

        