class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        sols = set()
        for i in range(len(nums)): 
            # find two sum for this in the list without this number
            target = -nums[i]
            l, r = i+1, len(nums)-1
            while l < r:
                current = nums[l] + nums[r]
                if current == target:
                    sols.add((nums[i], nums[l], nums[r]))
                    l +=1
                    r -=1
                elif current < target:
                    l +=1
                else: 
                    r -=1
        return [x for x in sols]
                


        