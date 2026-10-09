class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        final_list = []

        def dfs(curr_sum, curr_pointer, curr_list):
            if curr_sum == target:
                final_list.append(curr_list.copy())
                return

            if curr_sum > target or curr_pointer >= len(nums):
                return

            # Take the current number allow it to be used again.
            curr_list.append(nums[curr_pointer])
            dfs(
                curr_sum + nums[curr_pointer],
                curr_pointer,
                curr_list
            )
            curr_list.pop()

            # Skip this number.
            dfs(curr_sum, curr_pointer + 1, curr_list)

        dfs(0, 0, [])
        return final_list