from functools import cache
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        arr = [] * len(nums)
        @cache
        def dp(currPtr, currSum):
            # try add the current number to the sum and then try without 
            if currSum == target and currPtr == len(nums):
                return 1
            elif currPtr == len(nums):
                return 0
            return dp(currPtr +1, currSum + nums[currPtr]) + dp(currPtr+1, currSum - nums[currPtr])
        return dp(0, 0)

        