# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        def dfs(root, left_bound, right_bound) -> bool:
            if not root:
                return True
            
            if root.val > left_bound and root.val < right_bound:
                return dfs(root.left, left_bound, root.val) and dfs(root.right, root.val, right_bound)
            else:
                return False
            
        return dfs(root, float("-inf"), float("inf"))