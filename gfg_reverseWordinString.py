t = int(input())

while(t!=0):
    s = input()
    s = s.split('.')
    s=s[::-1]
    arr=''
    for i in s:
        arr+=(i+'.')
    arr=arr[:-1]
    print(arr)
    t = t-1