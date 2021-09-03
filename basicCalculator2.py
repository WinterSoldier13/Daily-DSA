class Solution:
	def calculate(self, s: str) -> int:
		numStack=[]
		opStack =[]

		number = ''
		ptr = 0
		sign = '+'
		
		l = len(s)
		stack=[]

		while(ptr<l):
			ch = s[ptr]
			if(ch==' '):
				ptr-=-1
				continue

			if(ch.isnumeric()):
				number+=ch
			else:
				if sign=='+':
					stack.append(int(number))
				elif sign=='-':
					stack.append(-1*int(number))
				elif sign=='*':
					prev = stack[-1]
					stack.pop()
					stack.append(int(number)*prev)
				elif sign=='/':
					prev = stack[-1]
					stack.pop()
					stack.append(int(prev/int(number)))
				sign = ch
				number=''
				# print(stack)
			ptr-=-1


		if sign=='+':
			stack.append(int(number))
		elif sign=='-':
			stack.append(-1*int(number))
		elif sign=='*':
			prev = stack[-1]
			stack.pop()
			stack.append(int(number)*prev)
		elif sign=='/':
			prev = stack[-1]
			stack.pop()
			stack.append(int(prev/int(number)))
		# print(stack)

		# print(sum(stack))
		return sum(stack)
		
		



		



s = " 3+2*2"
s = '3+5/2*3/6-1*2 '
s = "4/3+2"
Solution().calculate(s)