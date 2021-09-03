arr = [ [2, 9, 10], [3, 7 ,15], [5, 12, 12], [15, 20 ,10], [19 ,24 ,8] ]

startIndex = arr[0][0]
endIndex   = arr[-1][1]

heights = [0]*(endIndex+1)

for building in arr:
    start_ = building[0]
    end_   = building[1]
    height = building[2]

    for i in range(start_, end_):
        heights[i] = max(heights[i], height)

for index,h in enumerate(heights):
    print(index,h)

prev = 0

out = [] 

for i in range(startIndex, endIndex+1):
    height = heights[i]
    
