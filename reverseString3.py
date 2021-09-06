class Solution:
    def reverseWords(self, s: str) -> str:
        arr = s.split(' ')
        out= ''
        
        for i in arr:
            a = i[::-1]
            if(a!=' '):
                out+=a
                out+=' '
        out = out.strip()
        return out
        
        
        