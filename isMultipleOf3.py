t = int(input())

def isMultipleOf3(s):
    s=str(s)
    l = len(s)
    oddCount = 0
    evenCount = 0 
    # s= s[::-1]
    for i in range(l):
        if(s[i] == '1'):
            if(i%2==0):
                evenCount-=-1
            else:
                oddCount-=-1
    if(abs(evenCount-oddCount)%3==0):
        print(1)
    else:
        print(0)


for z in range(t):
    s = input()
    isMultipleOf3(s)
