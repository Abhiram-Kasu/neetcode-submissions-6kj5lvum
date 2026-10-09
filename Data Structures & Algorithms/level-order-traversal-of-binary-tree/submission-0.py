# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        if root is None:
            return []

        levels = []
        # bfs 
        queue = deque([])
        queue.append(root)
        while queue:
            curr_level = []
            for i in range(0,len(queue)):
                item = queue.popleft()
                if item.left:
                    queue.append(item.left)
                if item.right:
                    queue.append(item.right)

                curr_level.append(item.val)
            levels.append(curr_level)
        return levels


        