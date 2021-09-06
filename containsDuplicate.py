class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        
        hashmap = {}
        
        for i in nums:
            if(i in hashmap.keys()):
                return True
            hashmap[i] = 1
        return False
            
        