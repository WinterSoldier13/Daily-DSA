class Solution:
    def rob(self, nums: List[int]) -> int:
        l = len(nums)

        dp = [0]*l
        if(len(nums) == 0):
            return 0
        if(len(nums) == 1):
            return nums[0]
        dp[0] = nums[0]
        dp[1] = nums[1]

        for i in range(2,l):
            max_ = -1
            for j in range(i-2,-1,-1):
                max_ = max(max_, dp[j])
            dp[i] = max_ + nums[i]

        print(dp)
        return  max(dp)
        