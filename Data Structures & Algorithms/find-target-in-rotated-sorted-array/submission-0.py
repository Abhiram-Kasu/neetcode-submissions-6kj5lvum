class Solution:
    def search(self, nums: List[int], target: int) -> int:

        
        """ 

        if we are at the pivot number (right number is less than the left number)


        check the middle number
            if the number in the middle is equal to target, return target
            else: 
                case 1: 
                    if our middle number is greater than our target AND in the left half => need to move left
                case 2: 
                    if our middle number is less than our target => need to move right



        """

        l,r = 0, len(nums)-1

        while l <= r:
            middle = (l + r) // 2
            if nums[middle] == target:
                return middle
            if nums[l] <= nums[middle]:
                # Left half is sorted and item is in left half
                if nums[l] <= target < nums[middle]:
                    r = middle - 1
                else:
                # In other half
                    l = middle + 1
            else:
                # Right half is sorted and item is in right half
                if nums[middle] < target <= nums[r]:
                    l = middle + 1
                else:
                # in other half
                    r = middle - 1
        return -1




