class Solution:
    # @param A : list of integers
    # @return an integer
    def hammingDistance(self, arr):
	    l = len(arr)
	    
	    if(l == 0 or l == 1):
	        return 0
	    ans = 0
	    for i in range(32):
	        countOfIthBitSet = 0
	        for ele in arr:
	            if(ele & 1<<i):
	                countOfIthBitSet-=-1
            countOfIthBitNotSet = l - countOfIthBitSet
            ans+=(countOfIthBitSet*countOfIthBitNotSet*2)
        return ans%1000000007
        
    def cntBits(self, A):
        return self.hammingDistance(A)
        
# https://www.interviewbit.com/problems/different-bits-sum-pairwise/