"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None

        old_to_new = {}
        curr = head
        while curr:
            old_to_new[curr] = Node(curr.val)
            curr = curr.next

        # Second pass: connect next and random pointers.
        curr = head
        while curr:
            copied = old_to_new[curr]

            copied.next = old_to_new.get(curr.next)
            copied.random = old_to_new.get(curr.random)

            curr = curr.next

        return old_to_new[head]
            