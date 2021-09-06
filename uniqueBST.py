class Solution:
    hashmap = {}

    def factorial(self, n):
        if(n in self.hashmap.keys()):
            return self.hashmap[n]
        if(n == 0 or n==1):
            self.hashmap[n] = 1
            return 1
        else:
            self.hashmap[n] = n*self.factorial(n-1)
            return self.hashmap[n]
    def catalyn(self, n):
        twoNFact= self.factorial(2*n)
        nPlusFact = self.factorial(n+1)
        nFact = self.factorial(n)

        catalyn = int(twoNFact/(nPlusFact*nFact))
        return catalyn
ob = Solution()
t= int(input())

for _ in range(t):
    n = int(input())
    ans = ob.catalyn(n)
    print(ans)