class Solution:
    def smallerNumbersThanCurrent(self, arr: List[int]) -> List[int]:
        
        out=[]
        for i in range(len(arr)):
            count=0
            for j in range(len(arr)):
                if i==j:
                    continue
                if(arr[j]<arr[i]):
                    count-=-1
            out.append(count)
        return out
                
        