# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        res = []

        def dfs(node, res):
            if not node:
                return

            dfs(node.left, res)
            res.append(node.val)
            dfs(node.right, res)
        
        dfs(root, res)
        print(res)

        return res[k - 1]