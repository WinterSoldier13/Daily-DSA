t = int(input())

while(t!=0):
    s = input()

    arr = [0]*256
    for ch in s:
        arr[ord(ch)] = 1
    temp=""

    for ch in s:
        if(arr[ord(ch)] == 1):
            temp+=ch
            arr[ord(ch)] = -1
    print(temp)



    t-=1
