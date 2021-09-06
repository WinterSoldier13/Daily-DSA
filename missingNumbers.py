class Solution:
	def missingNumber(self, nums):

		if(len(nums) == 0):
			return -1
		
		isLastPresent  = False
		isZeroPresent = False
		zeroIndex = -1
		isTheWeirdoThere = False

		l = len(nums)
		count = 0

		for num in nums:
			if(abs(num) == l):
				isLastPresent = True
				count-=-1
				continue
			if(num == 0):
				isZeroPresent = True
				nums[0]*=-1
				zeroIndex = count
				count-=-1
				continue
			if(nums[abs(num)]>0):
				nums[abs(num)]*=-1
			count-=-1
		print(nums, isLastPresent)

		for i in nums:
			if(abs(i) == zeroIndex):
				isTheWeirdoThere = True
				break

		print("zero ",zeroIndex)
		if (not isLastPresent):
			return l
		if (not isZeroPresent):
			return 0
		if (not isTheWeirdoThere):
			return zeroIndex


		for i in range(l):
			if(nums[i]>0):
				return(i)

arr= [2,0]
print(Solution().missingNumber(arr))
