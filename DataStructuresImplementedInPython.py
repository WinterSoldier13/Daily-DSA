# DS in python

#  ____________________________________________________________________________________________________________________

# STACK
# It is nothing but list

class stack:
	arr = []
	def insert(self, x):
		self.arr.append(x)

	def pop(self):
		top = self.arr[-1]
		self.arr.pop()
		return top

	def size(self):
		return len(self.arr)

	def isEmpty(self):
		return len(self.arr)==0

stack = stack()
stack.insert(1)
stack.insert(2)
stack.insert(3)

print(stack.pop())
print(stack.pop())
print(stack.isEmpty())
print(stack.size())
stack.pop()
print(stack.size())

print("\n\nQueue")
#  ____________________________________________________________________________________________________________________

# Queue and doubly ended queue
import collections

q = collections.deque()
q.appendleft(1)
q.appendleft(2)
q.appendleft(3)

print(q.popleft())
print(q.pop())
print(q.pop())
print('\n\nHashmap')
#  ____________________________________________________________________________________________________________________

# Hashmap
hashmap={}
hashmap[1] = "Chester"
hashmap["Ayush"] = "Singh"
hashmap[5] = "Zedd"

for key in hashmap.keys():
	print(str(key)+" "+hashmap[key])

if "Ayush" in hashmap.keys():
	print("present")


#  ____________________________________________________________________________________________________________________

# Heaps
# By default minHeap is implemented
# to implemet maxHeap multiply by -1 while pushing and poping
print('\n\nHeaps')
import heapq

minHeap = [8,5,9,6,3,7,4,2,1]
heapq.heapify(minHeap)
print(heapq.heappop(minHeap))
print(minHeap)
print(heapq.heappush(minHeap,1))
print(minHeap)

while(len(minHeap)!=0):
	print(heapq.heappop(minHeap))