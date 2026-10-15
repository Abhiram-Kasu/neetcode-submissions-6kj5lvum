class Solution:


    def canPartition(self, nums: List[int]) -> bool:

        dp_arr = {}
        def dp(idx, left_sum, right_sum):
            if idx == len(nums): 
                return left_sum == right_sum
            key = (idx, left_sum, right_sum)
            if key in dp_arr:
                return dp_arr[key]
            
            # try putting each item in either right_sum or left_sum
            dp_arr[key] = dp(idx+1, left_sum + nums[idx], right_sum) or dp(idx+1, left_sum,  right_sum + nums[idx])
            return dp_arr[key]

        
        return dp(0,0,0)

            
        