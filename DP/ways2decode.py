# RECURSION 1 MY WAY
def possb(s :str, l: int):
    if(l==len(s)-1):
        return 1
    if(l==len(s)):
        return 1
    if int(s[l]) == 0:
        return 0
   
    
    res = possb(s,l+1)

    if(int(s[l:l+2])<=26):
        res+= possb(s,l+2)
    return res

# RECURSION 2
def recurse(s, l):
    if(l==0):
        return 1
    if(l==1):
        return 1
    res=0
    if(s[l-1]!='0'):
        res = recurse(s,l-2)
    res2 =0
    if(int(s[l-2:l])<=26):
        res2 = recurse(s,l-3)
    return res+res2


# Dynamic programming

def dynamic(s):
    if(s[0]=='0'):
        return 0
    dp = [0]*(len(s)+1)
    dp[0]=1
    dp[1]=1

    for i in range(2,len(s)+1):
        if(s[i-1]>'0'):
            dp[i] = dp[i-2]
        if(int(s[i-2:i])<=26):
            dp[i]+=dp[i-3]
    return dp[len(s)]

s="10"
print(possb(s,0))

# print(recurse(s,len(s)))
print(dynamic(s))