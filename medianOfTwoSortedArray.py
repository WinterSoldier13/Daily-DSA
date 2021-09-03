class Solution:
    def findMedianSortedArrays(self, arr1: List[int], arr2: List[int]) -> float:
        
        l1 = len(arr1)
        l2 = len(arr2)
        
        # //if input1 length is greater than switch them so that input1 is smaller than input2.
        # // In this way we will always work on the array with smaller length i.e. the input1
        if(l2<l1):
            return self.findMedianSortedArrays(arr2,arr1)
        
        low = 0
        high = l1
        
        while(low<=high):
            
            # // Remember the below two formulas for this question
            # // For more reference watch this YT Video: https://www.youtube.com/watch?v=LPFhl65R7ww
            partitionX = int((low+high)/2)
            partitionY = int((l1+l2+1)/2 - partitionX)
            

            # //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
            # //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
            leftX = -99999999999999
            rightX = 99999999999999
            
            leftY = -99999999999999
            rightY = 99999999999999
            
            if(partitionX!=0):
                leftX = arr1[partitionX-1]
            if(partitionX!=l1):
                rightX = arr1[partitionX]
            if(partitionY!=0):
                leftY = arr2[partitionY-1]
            if(partitionY!=l2):
                rightY = arr2[partitionY]
                
            if(leftX<=rightY and leftY<=rightX):
                if((l1+l2)%2==0):
                    return (max(leftX,leftY)+min(rightX,rightY))/2
                else:
                    return max(leftX,leftY)
            
            elif(leftX>rightY):
                high = partitionX-1
            else:
                low = partitionX+1
        
            

            
                
        
        