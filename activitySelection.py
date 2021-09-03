t= int(input())

for z in range(t):
	n=int(input())
	start=[]
	end=[]
	start = [int(x) for x in input().split(' ')]
	end = [int(x) for x in input().split(' ')]

	# n=6
	# start = [1,3,2,5,8,5]
	# end   = [2,4,6,7,9,9]
	slots=[]
	for i in range(n):
		slots.append([end[i], start[i]])
	slots = sorted(slots)

	print(slots)

	for i in range(len(slots)):
		temp = slots[i][0]
		slots[i][0] = slots[i][1]
		slots[i][1] = temp
	print(slots)

	stack=[]

	for slot in slots:
		if(len(stack) == 0):
			stack.append(slot)
			continue
		if(slot[0]<stack[-1][1]):
			continue
		else:
			stack.append(slot)
	print(stack)
	print(len(stack))
	
