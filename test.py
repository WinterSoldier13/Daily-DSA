chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

# inp = 'AB'
# inp2 = 'AAA'
# inp3 = 'ZZ'
inp = input("Enter the characters: ")
l = len(inp)


hashmap={}

for index,ch in enumerate(chars):
    hashmap[ch] = index+1

ptr = l-1
sum_=0

for i in inp:
    sum_ = sum_ + 26**ptr*hashmap[i]
    ptr-=1

print(sum_)

