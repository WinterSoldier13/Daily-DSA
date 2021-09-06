class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        
        end_index = int(len(nums)/2)-1
        arr=[]
        
        for i in range(0,end_index+1):
            arr.append(nums[i])
            arr.append(nums[i+end_index+1])
        return arr
        