class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        nums.append(float('inf'))
        res = []
        l = 0
        for r in range(1,len(nums)):
            if nums[r] == nums[r-1]+1:
                continue  
            if nums[r] > nums[r-1]+1:
                if r-1 == l:
                    res.append(str(nums[l]))
                else:
                    res.append(str(nums[l])+'->'+str(nums[r-1]))
                l = r
        return res
