def addnode(a, b):
    mem[a].append(b)


def add(a):
    mem[a] = []

def dfs(s,d):
    for i in mem[s]:
        if i in lst:
            continue
        elif i in nolst:
            continue
        elif d in mem[i] :
            lst.append(i)
        else :
            dfs(i,d)
            if i not in lst:
                nolst.append(i)

n = int(input())
mem = {}
lst=[]
nolst=[]
for i in range(n):
    x = int(input())
    add(x)

c = int(input())
for i in range(c):
    x = int(input())
    y = int(input())
    addnode(x, y)

x = int(input())
y = int(input())
if y in mem[x]:
    lst.append(x)
dfs(x,y)
lst.sort()
print(lst)
