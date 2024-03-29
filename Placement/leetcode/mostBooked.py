import heapq
from collections import defaultdict 
class Solution():
    def mostBooked(self, n, meetings):
        booked = []
        free = list(range(n))
        meetings.sort()
        freq = defaultdict(int) #empty dictionary

        for start, end in meetings:
            while booked and booked[0][0]<=start: #while booked not empty and end time of ongoing meeting is less than or equal to  start time of current meeting
                _, room = heapq.heappop(booked) #the room occupied is removed from the booked heap
                heapq.heappush(free,room) #the removed room is added to the free rooms heap
            
            if free: # if free is not empty
                room = heapq.heappop(free) # get the free room with lowest no
                heapq.heappush(booked,[end,room]) #allot room for current meeting
            
            else: # is free is empty
                r,room = heapq.heappop(booked) # meeting with lowest end time is taken out from booked, with the alloted room
                heapq.heappush(booked,[r+end-start,room]) # calculate new end time and allot new booking for the meeting in the same room 
            
            freq[room]+=1 #update the dictionary for no of meetings in a room

        return max(freq,key=freq.get) #return the max frequency, in case of tie 1st occurance is returned

m = [[0,10],[1,5],[2,7],[3,4]]
n = 2
s1 = Solution()
print(s1.mostBooked(n,m))