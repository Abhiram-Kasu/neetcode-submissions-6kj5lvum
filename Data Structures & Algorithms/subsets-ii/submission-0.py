class Solution:


    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        final_list = []
        def dfs(index,curr):
            if index >= len(nums):
                final_list.append(curr)
                return
            # pick the item at index
            
            dfs(index + 1, curr + [nums[index]])
            next_index = index + 1
            while next_index < len(nums) and nums[next_index] == nums[index]:
                next_index += 1
            dfs(next_index, curr)
        dfs(0,[])
        return final_list