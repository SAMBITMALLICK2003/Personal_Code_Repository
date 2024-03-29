import heapq

#Heap Queue ( priority queue ) problem

class Solution():
    def furthestBuilding(heights, bricks, ladders):
        k = []
        for i in range(len(heights)-1):
            diff = heights[i+1]-heights[i]
            if(diff<=0):
                continue
            bricks-=diff
            x = heapq.heappush(k,-diff)
            if(bricks<0):
                bricks+=-heapq.heappop(k)
                ladders-=1
            if(ladders<0):
                return i
        return len(heights)-1
        
h = [4,2,7,6,9,14,12]
b = 5
l = 1
print(Solution.furthestBuilding(h,b,l))