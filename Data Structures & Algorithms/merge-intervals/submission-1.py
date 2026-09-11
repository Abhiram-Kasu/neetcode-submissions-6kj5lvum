class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        final_list = []
        intervals.sort()
        # go through every set 
        curr_ptr = 0
        while curr_ptr < len(intervals):

            start, end = intervals[curr_ptr]
            merge_ptr = curr_ptr + 1
            while merge_ptr < len(intervals) and intervals[merge_ptr][0] <= end:
                end = max(end, intervals[merge_ptr][1])
                merge_ptr += 1
            final_list.append([start, end])
            curr_ptr = merge_ptr
        return final_list
            

        