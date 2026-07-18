"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""
import heapq

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:

        if not intervals: 
            return 0

        intervals.sort(key=lambda x: x.start)

        rooms = []
        for interval in intervals: 
            #check if we can use the latest room
            if rooms and rooms[0] <= interval.start:
                heapq.heappop(rooms)
            #push to new room

            heapq.heappush(rooms, interval.end)
        return len(rooms)