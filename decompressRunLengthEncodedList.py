class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        out=[]
        for i in range(0,len(nums)-1,2):
            freq = nums[i]
            ele = nums[i+1]

            for i in range(freq):
                out.append(ele)
        print(out)
        return out
        