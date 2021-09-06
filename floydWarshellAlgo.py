#code
t=int(input())
while(t!=0):
	n=int(input())

	temp=[0]*n
	graph = [temp]*n

	for i in range(n):
		line = input()
		line = line.split(' ')
		temp=[]
		for x in line:
			temp.append(int(x))
		graph[i] = temp

# 	print(graph)
	dist = graph

	for k in range(0,n):
		for i in range(0,n):
			for j in range(0,n):
				if(dist[i][j]> dist[i][k] + dist[k][j]):
					dist[i][j] = dist[i][k] + dist[k][j]

	for i in range(n):
		for j in range(n):
			print((dist[i][j])==10000000?'INF':dist[i][j],end=" ")
		print()
	t-=1