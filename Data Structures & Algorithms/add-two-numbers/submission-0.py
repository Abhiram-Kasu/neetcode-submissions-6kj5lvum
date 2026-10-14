# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    ## recursive solution
    ## go to the end of the list
    ## add curr plus any remainder 



    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        tail = dummy
        carry = 0
        while l1 or l2 or carry:
            curr_sum = carry
            if l1:
                curr_sum += l1.val
                l1 = l1.next
            if l2: 
                curr_sum += l2.val
                l2 = l2.next
            carry, digit = divmod(curr_sum, 10)
            tail.next = ListNode(digit)
            tail = tail.next
        return dummy.next
        

        