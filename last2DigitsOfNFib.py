
class Solution:
    hashmap = {1 : 1, 2: 1}

    def preCompute(self):
        for i in range(3, 301):
            self.hashmap[i] = (self.hashmap[i-1] + self.hashmap[i-2])%100
    
    def getLast2digit(self, n):
        return self.hashmap[n%300]

T = int(input())
ob = Solution()
ob.preCompute()
while(T>0):
    T-=1
    n = int(input())

    print(ob.getLast2digit(n))


