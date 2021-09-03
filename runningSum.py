class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        
        sum_ = nums[0]
        arr=[sum_]
        
        for i in range(1,len(nums)):
            arr.append(arr[-1]+nums[i])
        return arr