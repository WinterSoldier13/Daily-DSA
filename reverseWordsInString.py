class Solution:
    def reverseWords(self, s: str) -> str:
        arr = [x.strip() for x in s.split(' ')]
        for i in range(len(arr)):
            arr[i] = arr[i].strip()
        print(arr)
        arr = arr[::-1]

        newString =''
        for i in arr:
            if(len(i)>0):
                newString+=(i+' ')
        newString = newString.strip()
        return newString