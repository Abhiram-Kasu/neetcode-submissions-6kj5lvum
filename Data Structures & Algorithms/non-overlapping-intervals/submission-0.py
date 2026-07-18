class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        """start at intervval i
        if i and i+1 overlap, check for both scenarios
        dp on checking if you remove i and if you remove i+1,
        kind of a sliding window? 
        """ 
        ## sort all intervals by last item

        intervals.sort(key=lambda x: x[1])

        kept = 1
        prev_end = intervals[0][1]

        for start, end in intervals[1:]:
            if start >= prev_end:
                kept += 1
                prev_end = end

        return len(intervals) - kept
        