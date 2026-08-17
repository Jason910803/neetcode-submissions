# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:

        def dfs(node, depth):
            if not node:
                return depth

            depth += 1

            depth_left = dfs(node.left, depth)
            depth_right = dfs(node.right, depth)

            depth -= 1

            return max(depth_left, depth_right)
        
        return dfs(root, 0)