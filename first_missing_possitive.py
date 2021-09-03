# Test Commit 1
def seperateNegatives(arr):
    i=0
    j=0
    l= len(arr)
    for i in range(l):
        if(arr[i]<0):
            temp = arr[i]
            arr[i]=arr[j]
            arr[j] = temp
            j-=-1
    for i in range(j):
        arr=arr[1:]
    return arr


def firstMissingPositive(arr):
    l = len(arr)
    if(l==0):
        return 1
    if(l==1 and arr[0]==1):
        return 2
    elif(l==1):
        return 1
    allN = True
    
    for c in arr:
        if c>0:
            allN = False
            break
    if(allN):
        return 1
    
    arr = seperateNegatives(arr)
    l = len(arr)
    
    for i in range(l):
        ele = abs(arr[i])-1
        if ele<l:
            if(arr[ele]>0):
                arr[ele]*=-1
    # print(arr)

    ans=0
    for c in range(l):
        if(arr[c]>0):
            ans= c+1
            break
    if(ans==0):
        ans = l+1
    return ans
    
    
    

arr=[1,2,3,4,5,6]
# print(arr.index(1))

print(firstMissingPositive(arr))


